#include <stdio.h>

int main() {
    int op;
    float n1, n2;
    char continuar;

    do {
        printf("\n=== CALCULADORA ===\n");
        printf("1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n");
        printf("Escolha a opcao: ");
        scanf("%d", &op);

        printf("Digite o primeiro numero: ");
        scanf("%f", &n1);
        printf("Digite o segundo numero: ");
        scanf("%f", &n2);

        switch(op) {
            case 1:
                printf("Resultado: %.2f\n", n1 + n2);
                break;
            case 2:
                printf("Resultado: %.2f\n", n1 - n2);
                break;
            case 3:
                printf("Resultado: %.2f\n", n1 * n2);
                break;
            case 4:
                if(n2 != 0)
                    printf("Resultado: %.2f\n", n1 / n2);
                else
                    printf("Erro: divisao por zero!\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

        printf("Deseja realizar outra operacao? (s/n): ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

    return 0;
}
