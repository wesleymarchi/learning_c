#include <stdio.h>

int main() {
    int opcao, i, num;

    do {
        printf("\n=== MENU TABUADA ===\n");
        printf("1 - Tabuada de um numero\n");
        printf("2 - Todas as tabuadas de 1 a 10\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o numero: ");
                scanf("%d", &num);
                for(i = 1; i <= 10; i++)
                    printf("%d x %d = %d\n", num, i, num * i);
                break;

            case 2:
                for(num = 1; num <= 10; num++) {
                    printf("\nTabuada do %d:\n", num);
                    for(i = 1; i <= 10; i++)
                        printf("%d x %d = %d\n", num, i, num * i);
                }
                break;

            case 3:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 3);

    return 0;
}
