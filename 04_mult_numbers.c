/* Multiplica dois números inteiros */

#include <stdio.h>  // Header

int main() {
    int x, y, mult;

    printf("Insira o primeiro numero:\n");
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    mult = x * y;   // Multiplicação

    printf("Resultado da multiplicacao: %d\n", mult);

    return 0;
}