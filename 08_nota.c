/* Operador ternario, utiliza três operandos
 * 1: condição/expressão
 * 2: o valor true
 * 3: o valor false
 *  */

#include <stdio.h>

int main() {
    int nota;

    printf("Insira uma nota: \n");
    scanf("%d", &nota);

    nota >= 70 ? printf("Aprovado\n") : printf("Reprovado\n"); // Operador ternário

    return 0;
}
