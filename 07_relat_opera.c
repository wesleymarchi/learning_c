/* Operadores relacionais, utilizando estrutura de seleção if */

#include <stdio.h>

int main() {
    int x, y;

    printf("Insira o primeiro numero:\n");
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    if (x == y)
      printf("%d eh igual a %d\n", x, y);

    if (!(x != y))
      printf("%d eh diferente de %d\n", x, y);

    if (x > y)
      printf("%d eh maior que %d\n", x, y);

    if (x >= y)
      printf("%d eh maior ou igual a %d\n", x, y);

    if (x < y)
      printf("%d eh menor que %d\n", x, y);

    if (x <= y)
      printf("%d eh menor ou igual a %d\n", x, y);

    return 0;
}