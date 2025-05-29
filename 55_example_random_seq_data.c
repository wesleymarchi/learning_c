/* Lê sequencialmente um arquivo de acesso aleatório (binario), atualiza os dados, cria novos dados e exclui */

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

    // Tenta abrir o arquivo para leitura e escrita
    if ((cfPtr = fopen("credito.dat", "r+")) == NULL) {
        // Se não existir, cria o arquivo com w+ (zera se já existir)
        if ((cfPtr = fopen("credito.dat", "w+")) == NULL) {
            printf("Erro ao criar o arquivo 'credito.dat'!\n");
            return 1;
        } else {
            // Inicializa o arquivo com 100 registros vazios
            struct dadosCliente vazio = {0, "", "", 0.0};
            for (int i = 0; i < 100; i++) {
                fwrite(&vazio, sizeof(struct dadosCliente), 1, cfPtr);
            }
            rewind(cfPtr);
            printf("Arquivo 'credito.dat' criado com sucesso.\n");
        }
    }

    // Menu principal
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
            default:
                printf("Opcao invalida.\n");
        }
    }

    fclose(cfPtr);
    return 0;
}

// Show menu
int showMenu(void) {
    int op;

    printf("\nEscolha uma opcao\n"
           "1 -> Salvar em TXT\n"
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
        rewind(lePtr);  // posiciona o ponteiro de leitura no inicio do arquivo binário (byte 0)
        // Define o cabeçalho no novo arquivo txt
        fprintf(gravaPtr, "%-6s%-16s%-11s%-10s\n", "Conta", "Nome", "Sobrenome", "Saldo");

        // Lê os registros do binário e escreve no arquivo txt
        // ponteiro para onde será armazenado; tamanho do item a ser lido; item a ser lido; ponteiro para o arquivo
        while (fread(&cliente, sizeof(struct dadosCliente), 1, lePtr) == 1) {  // registro lido
            if (cliente.numConta != 0) {
                fprintf(gravaPtr, "%-6d%-16s%-11s%10.2f\n",
                        cliente.numConta, cliente.nome, cliente.sobrenome, cliente.saldo);
            }
        }

        fclose(gravaPtr);
    }
}

void new(FILE *fPtr) {
    struct dadosCliente cliente;
    int numConta;

    printf("Insira o numero da nova conta (1 - 100): ");
    scanf("%d", &numConta);

    // Ponteiro para arquivo; deslocamento em bytes (posição); origem do deslocamento (inicio byte 0)
    fseek(fPtr, (numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
    // Ponteiro para onde os dados lidos serão armazenados; tamanho em byte de cada item; n de item; ptr de onde será lido
    fread(&cliente, sizeof(struct dadosCliente), 1, fPtr);

    if (cliente.numConta != 0) {
        printf("Conta #%d ja existe.\n", numConta);
    } else {
        printf("Insira nome, sobrenome e saldo\n");
        scanf("%s%s%f", cliente.nome, cliente.sobrenome, &cliente.saldo);
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
        printf("Insira o valor de credito (+) ou debito (-): ");
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
        fwrite(&clienteNulo, sizeof(struct dadosCliente), 1, fPtr);
        printf("Conta #%d excluida.\n", numConta);
    }
}