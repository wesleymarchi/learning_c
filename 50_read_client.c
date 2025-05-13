/* Buscando dados no arquivo de acesso sequencial */

#include <stdio.h>
#include <string.h>

int main() {
    int conta, busca;
    char nome[40];
    float saldo;
    FILE *cfPtr;

    printf("Qual conta deseja buscar?\n");
    scanf("%d", &busca);

    if ((cfPtr = fopen("clientes.dat", "r")) == NULL) {  // Tenta abrir o arquivo
        printf("O arquivo nao pode ser aberto.\n");
        return 1;
    } else {
        printf("%-10s%-13s%s\n", "Conta", "Nome", "Saldo");

        // Lê os dados enquanto fscanf retornar 3 itens corretamente lidos
        while (fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo) == 3) {
            if (conta == busca) {
              printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
              break;
            }
        }

        fclose(cfPtr);
    }

    return 0;
}