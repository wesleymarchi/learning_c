/* Precedencia ao calcular sempre da esquerda para a direira, entre parenteses é prioritario;
 * seguido de multiplicação, divisão ou modulo; em seguida adição ou subtração */

#include <stdio.h>

int main() {
    int x, y, z, p1, p2;

    printf("Insira o primeiro numero:\n");
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    printf("Insira o terceiro numero:\n");
    scanf("%d", &z);

    p1 = z + x * y;
    p2 = (z - x) * y;

    printf("Resultado P1: %d\n", p1);
    printf("Resultado P2: %d\n", p2);

    return 0;
}