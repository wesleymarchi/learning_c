/* Estrutura de seleção if aninhada */

#include <stdio.h>

int main() {
    int nota;

    printf("Insira uma nota:\n");
    scanf("%d", &nota);

    if (nota >= 90)
      printf("A\n");
    else if (nota >= 80)
      printf("B\n");
    else if (nota >= 70)
      printf("C\n");
    else if (nota >= 60)
      printf("D\n");
    else
      printf("F\n");

    return 0;
}