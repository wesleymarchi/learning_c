/* Subtração entre dois números inteiros */

#include <stdio.h>

int main() {
    int x, y, sub;

    printf("Insira o primeiro numero:\n");
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    sub = x - y;   // Subtração

    printf("Resultado da subtracao: %d\n", sub);

    return 0;
}