/* Função para retornar o maior valor entre três números */

#include <stdio.h>

int maximum(int, int, int);

int main() {
  int a, b, c;

  printf("Digite tres numeros inteiros: ");
  scanf("%d %d %d", &a, &b, &c);

  printf("O maior eh: %d\n", maximum(a, b, c));

  return 0;
}

int maximum(int x, int y, int z) {
  int max = x;

  if (y > max)
    max = y;

  if (z > max)
    max = z;

  return max;
}