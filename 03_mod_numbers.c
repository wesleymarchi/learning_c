/* Resto da divisão entre dois números inteiros */

#include <stdio.h>  // Header

int main() {
    int x, y, rest;

    printf("Insira o primeiro numero:\n");
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    rest = x % y;   // Operador de módulo/resto da divisão

    printf("Resultado resto da divisao: %d\n", rest);

    return 0;
}