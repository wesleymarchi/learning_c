/* Utilizando estrutura de repetição (loop) while,
 * calcula a média de 3 notas inseridas */

#include <stdio.h>

int main() {
    int k, nota, total;
    float media;

    total = 0;
    k = 0;  // Contador

    //  Loop while
    while (k < 3) {
      printf("Insira uma nota:\n");
      scanf("%d", &nota);
      total += nota;
      k++;    // pós-incremento
    }

    media = (float) total / k;  // Coersão

    printf("A media eh: %.2f\n", media);    // %.2f: especificador de conversão, retorna duas casas decimais

    return 0;
}