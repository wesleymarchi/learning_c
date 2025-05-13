/* Programa que permite obter a lista de clientes com crédito zerado (não devem dinheiro)
 * clientes com saldo credor (a empresa deve dinheiro)
 * clientes com saldo devedor (clientes que devem dinheiro)
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int pedido, conta;
    float saldo;
    char nome[50];
    FILE *cfPtr;

    if ((cfPtr = fopen("clientes.dat", "r")) == NULL) {
        printf("O arquivo nao pode ser aberto.\n");
    } else {
        printf("Digite uma opcao\n"
            "1 -> Lista contas com saldo zero\n"
            "2 -> Lista contas com saldo credor\n"
            "3 -> Lista contas com saldo devedor\n"
            "4 -> Sair\n");
        scanf("%d", &pedido);

        while (pedido != 4) {
            fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);

            switch (pedido) {
                case 1:
                    printf("\nContas com saldo zerado:\n");
                    while (!feof(cfPtr)) {
                        if (saldo == 0)
                            printf("%-10d%-13s%7.2f\n", conta, nome, saldo);

                        fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);
                    }
                    break;
                case 2:
                    printf("\nContas com saldo credor:\n");
                    while (!feof(cfPtr)) {
                        if (saldo < 0)
                            printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
                        fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);
                    }
                    break;
                case 3:
                    printf("\nContas com saldo devedor:\n");
                    while (!feof(cfPtr)) {
                        if (saldo > 0)
                            printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
                        fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo);
                    }
                    break;
            }

            // rewind() faz com que o ponteiro de posição do arquivo (indicando o número do próximo byte do arquivo a
            // ser lido ou gravado) seja reposicionado no inicio do arquivo (byte 0); chamado de offset de arquivo
            rewind(cfPtr);
            printf("Deseja continuar?\n");
            scanf("%d", &pedido);
        }
        fclose(cfPtr);
    }
    return 0;
}
