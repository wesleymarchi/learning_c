/* Lê sequencialmente um arquivo de acesso aleatório, atualiza os dados, cria novos dados e exclui */

#include <stdio.h>

struct dadosCliente {
    int numConta;
    char nome[20];
    char sobrenome[20];
    float saldo;
};

int showMenu(void);
void textFile(FILE *);
void update(FILE *);
void new(FILE *);
void delete(FILE *);

int main() {
    FILE *cfPtr;
    int op;

    if ((cfPtr = fopen("credito.dat", "r+")) == NULL) {
        printf("O arquivo nao pode ser aberto!\n");
    } else {
        while ((op = showMenu()) != 5) {
            switch (op) {
                case 1:
                    textFile(cfPtr);
                    break;
                case 2:
                    update(cfPtr);
                    break;
                case 3:
                    new(cfPtr);
                    break;
                case 4:
                    delete(cfPtr);
                    break;
            }
        }
        fclose(cfPtr);
    }

    return 0;
}

int showMenu(void) {
    int op;

    printf("\nEscolha uma opcao\n"
           "1 -> Armazena um arquivo formatado de texto das contas\n"
           "2 -> Atualiza uma conta\n"
           "3 -> Adiciona uma nova conta\n"
           "4 -> Exclui uma conta\n"
           "5 -> Sair\n");
    scanf("%d", &op);

    return op;
}

void textFile(FILE *lePtr) {
    struct dadosCliente cliente;
    FILE *gravaPtr;

    if ((gravaPtr = fopen("contas.txt", "w")) == NULL) {
        printf("O arquivo nao pode ser aberto!\n");
    } else {
        rewind(lePtr);
        fprintf(gravaPtr, "%-6s%-16s%-11s%-10s\n", "Conta", "Nome", "Sobrenome", "Saldo");

        // CORRIGIDO: leitura segura com fread
        while (fread(&cliente, sizeof(struct dadosCliente), 1, lePtr) == 1) {
            if (cliente.numConta != 0) {
                fprintf(gravaPtr, "%-6d%-16s%-11s%10.2f\n",
                        cliente.numConta, cliente.nome, cliente.sobrenome, cliente.saldo);
            }
        }

        fclose(gravaPtr);
        // fclose(lePtr); // REMOVIDO: não fechar aqui
    }
}

void new(FILE *fPtr) {
    struct dadosCliente cliente;
    int numConta;

    printf("Insira o numero da nova conta (1 - 100): ");
    scanf("%d", &numConta);

    fseek(fPtr, (numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
    fread(&cliente, sizeof(struct dadosCliente), 1, fPtr);

    if (cliente.numConta != 0) {
        printf("Conta #%d ja existe.\n", numConta);
    } else {
        printf("Insira nome, sobrenome e saldo\n");
        scanf("%s%s%f", cliente.nome, cliente.sobrenome, &cliente.saldo); // Corrigido
        cliente.numConta = numConta;

        fseek(fPtr, (numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
        fwrite(&cliente, sizeof(struct dadosCliente), 1, fPtr);
    }
}

void update(FILE *fPtr) {
    struct dadosCliente cliente;
    float transacao;
    int conta;

    printf("Insira o numero da conta para atualizacao (1 - 100): ");
    scanf("%d", &conta);

    fseek(fPtr, (conta - 1) * sizeof(struct dadosCliente), SEEK_SET);
    fread(&cliente, sizeof(struct dadosCliente), 1, fPtr);

    if (cliente.numConta == 0) {
        printf("Conta #%d sem informacoes.\n", conta);
    } else {
        printf("%-6d%-16s%-11s%10.2f\n\n",
               cliente.numConta, cliente.nome, cliente.sobrenome, cliente.saldo);
        printf("Insira o valor (+) ou pagamento (-): ");
        scanf("%f", &transacao);

        cliente.saldo += transacao;

        printf("%-6d%-16s%-11s%10.2f\n",
               cliente.numConta, cliente.nome, cliente.sobrenome, cliente.saldo);

        fseek(fPtr, (conta - 1) * sizeof(struct dadosCliente), SEEK_SET);
        fwrite(&cliente, sizeof(struct dadosCliente), 1, fPtr);
    }
}

void delete(FILE *fPtr) {
    struct dadosCliente cliente, clienteNulo = {0, "", "", 0.0};
    int numConta;

    printf("Insira o numero da conta para exclusao (1 - 100): ");
    scanf("%d", &numConta);

    fseek(fPtr, (numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
    fread(&cliente, sizeof(struct dadosCliente), 1, fPtr);

    if (cliente.numConta == 0) {
        printf("Conta #%d nao existe.\n", numConta);
    } else {
        fseek(fPtr, (numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
        fwrite(&clienteNulo, sizeof(struct dadosCliente), 1, fPtr); // Corrigido
        printf("Conta #%d excluída.\n", numConta);
    }
}