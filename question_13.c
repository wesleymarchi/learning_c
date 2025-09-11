/* Ler 6 números e exibir o vetor em ordem inversa  */

#include <stdio.h>

int main() {
    int vetor[6];

    printf("Digite 6 numeros inteiros:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Vetor invertido:\n");
    for (int i = 5; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}