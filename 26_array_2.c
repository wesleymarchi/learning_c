/* A diretiva "#define" define uma "constante simbólica", que é um identificador que é substituído por
 * um texto de substituição pelo pré-processador da linguagem C antes do programa ser compilado
 */

#include <stdio.h>
#define SIZE 10

int main() {
    int n[SIZE];

    for (int i = 0; i < SIZE; i++) // Inicializa os elementos do array com pares de 2 a 20
        n[i] = 2 + 2 * i;

    printf("%s%13s\n", "Elemento", "Valor");

    for (int i = 0; i < SIZE; i++)
        printf("%8d%13d\n", i, n[i]);

    return 0;
}