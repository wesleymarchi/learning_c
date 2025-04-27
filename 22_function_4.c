/* Para obter números randomicos, utiliza-se srand(),
 * ela utiliza um argumento inteiro unsigned para ser a "semente",
 * produzindo uma sequência diferente de números aleatórios
 * unsigned é uma abreviação para unsigned int.
 * */

#include <stdio.h>
#include <stdlib.h>

int rollDice(void);

int main() {
  unsigned seed = 42; // mantem o padrão

  srand(seed);
  for (int i = 0; i < 20; i++) {
    printf("%10d", rollDice());
    if ((i + 1) % 5 == 0)
      printf("\n");
  }

  return 0;
}

int rollDice(void) {
  return (1 + (rand() % 6));
}