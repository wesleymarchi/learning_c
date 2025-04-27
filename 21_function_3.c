/* Simula o lançamento de um dado e imprime cada lançamento
 * rand() gera números pseudo-aleatórios
 * A sequência se repete cada vez que o programa é executado.
 */

#include <stdio.h>
#include <stdlib.h>

int r();

int main() {
  for (int i = 0; i < 20; i++) {
    printf("%10d", r());

    if ((i+1) % 5 == 0)
      printf("\n");
  }

  return 0;
}

int r() {
  return (1 + (rand() % 6)); // Retorna um número aleatório; "ajuste de escala"
}