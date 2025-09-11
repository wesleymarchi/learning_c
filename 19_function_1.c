/* Definindo uma função simples que retorna o quadrado de um número */

#include <stdio.h>

int square(int); // Protótipo de função; parâmetro definido

int main() {
    int x;

    for (x = 0; x < 5; x++)
      printf("%d\n", square(x)); // Passando argumento para a função

    return 0;
}

/* Definição da função */
int square(int x) {
  return x * x;
}