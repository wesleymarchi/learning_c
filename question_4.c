/* Verificar se um número é positivo, negativo ou se é zero */

#include <stdio.h>

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    if (n > 0) {
        printf("O numero eh positivo.\n");
    } else if (n < 0) {
        printf("O numero eh negativo.\n");
    } else {
        printf("O numero eh zero.\n");
    }

    return 0;
}
