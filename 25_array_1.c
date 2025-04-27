/* Um array é um grupo de locais na memória relacionados com o mesmo tipo de dados */

#include <stdio.h>

int main() {
    int n[10], i; // Define o tamanho do array

    // preenche o array
    for (i = 0; i < 10; i++) {
        n[i] = i + 1; // Atribuição de um valor para uma determinada posição do array
    }

    printf("%s%13s\n", "Elemento", "Valor");

    for (i = 0; i < 10; i++)
        printf("%7d%13d\n", i, n[i]);

    return 0;
}
