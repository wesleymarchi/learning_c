#include <stdio.h>

int main() {
    int n, i;
    int pares = 0, impares = 0, positivos = 0, negativos = 0, zeros = 0;

    for(i = 1; i <= 4; i++) {
        printf("Digite o %d numero: ", i);
        scanf("%d", &n);

        // Par ou ímpar
        if(n % 2 == 0)
            pares++;
        else
            impares++;

        // Positivo, negativo ou zero
        switch (n > 0 ? 1 : (n < 0 ? -1 : 0)) {
            case 1:
                positivos++;
                break;
            case -1:
                negativos++;
                break;
            case 0:
                zeros++;
                break;
        }
    }

    printf("\nPares: %d\nImpares: %d\nPositivos: %d\nNegativos: %d\nZeros: %d\n",
           pares, impares, positivos, negativos, zeros);

    return 0;
}
