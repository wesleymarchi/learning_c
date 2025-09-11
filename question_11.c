/* Ler 5 elementos inteiros e soma-los */

#include <stdio.h>

int main() {
    int numeros[5];
    int soma = 0;

    printf("Digite 5 numeros inteiros:\n");

    for (int i = 0; i < 5; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    printf("Soma dos elementos = %d\n", soma);

    return 0;
}
