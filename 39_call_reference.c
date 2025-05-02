/* Chamada/passagem por referencia */
#include <stdio.h>

void cuboPorReferencia(int *);

int main() {
    int n = 5;

    printf("O valor original do numero eh %d\n", n);

    cuboPorReferencia(&n);  // referência
    printf("O novo valor do numero eh %d\n", n);

    return 0;
}

void cuboPorReferencia(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr;  // Para realizar modificação, utiliza-se o operador de referência para modificar
}