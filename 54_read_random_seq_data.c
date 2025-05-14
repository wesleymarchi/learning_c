/* Lendo um arquivo de acesso aleatório */

#include <stdio.h>

struct dadosCliente {
    int numConta;
    char nome[20];
    char sobrenome[20];
    float saldo;
};

int main() {
    struct dadosCliente cliente;
    FILE *cfPtr;

    if ((cfPtr = fopen("credito.dat", "r")) == NULL) {
        printf("O arquivo nao pode ser aberto\n");
    } else {
        printf("%-6s%-16s%-11s%10s\n", "Conta", "Nome", "Sobrenome", "Saldo");
        while (!feof(cfPtr)) {
            // Lê dados binários
            // endereço onde os dados lidos serão armazenados;
            // sizeof para identificar o tamanho de cada bloco
            // 1 representa um bloco
            // cfPtr ponteiro para o arquivo aberto no modo leitura (r)
            fread(&cliente, sizeof(struct dadosCliente), 1, cfPtr);

            if (cliente.numConta != 0)
                printf("%-6d%-16s%-11s%10.2f\n", cliente.numConta, cliente.nome,cliente.sobrenome, cliente.saldo);
        }
    }
    fclose(cfPtr);

    return 0;
}