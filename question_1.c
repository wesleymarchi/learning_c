/* Verificar se o número é par ou ímpar */

#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("O numero é par.\n");
    } else {
        printf("O numero é impar.\n");
    }

    return 0;
}
