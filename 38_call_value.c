/* Chamada/passagem por valor/cópia */
#include <stdio.h>

int cuboPorValor(int);

int main() {
    int n = 5;

    printf("O valor original do numero eh %d\n", n);

    n = cuboPorValor(n);  // Valor/cópia
    printf("O novo valor do numero eh %d\n", n);

    return 0;
}

int cuboPorValor(int n) {
    return n * n * n;
}