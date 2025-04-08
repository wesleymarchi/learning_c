/* Estrutura de seleção multipla switch case
* Os caracteres podem ser armazenados em um tipo inteiro pois são representados com inteiros de 1 byte
* Cada caractere é representado por um inteiro na tabela ASCII
 */

#include <stdio.h>

int main() {
    int nota;
    int aK = 0, bK = 0, cK = 0, dK = 0, fK = 0;

    printf("Insira os conceitos (A, B, C, D, F)\nPara finalizar (q)\n");

    while ((nota = getchar()) != 'q') { // getchar(): lê um caractere do teclado
      switch (nota) { // expressão inteira/valor inteiro
        case 'A': // Conjunto de case: faz com que executem uma mesma ação
        case 'a':
          ++aK;
          break;
        case 'B':
        case 'b':
          ++bK;
          break;
        case 'C':
        case 'c':
          ++cK;
          break;
        case 'D':
        case 'd':
          ++dK;
          break;
        case 'F':
        case 'f':
          ++fK;
          break;
        case '\n':
        case ' ':
          break;
        default: // caso não seja nenhuma das opções anteriores
          printf("Conceito incorreto.\nInsira um conceito correto:\n");
          break;
      }
    }

    printf("\nOs totais de cada conceito:\n");
    printf("A = %d\n", aK);
    printf("B = %d\n", bK);
    printf("C = %d\n", cK);
    printf("D = %d\n", dK);
    printf("F = %d\n", fK);

    return 0;
}