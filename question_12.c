/* Ler 10 valores e encontrar o maior e menor */

#include <stdio.h>

int main() {
    int valores[10];
    int maior, menor;

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    maior = menor = valores[0];

    for (int i = 1; i < 10; i++) {
        if (valores[i] > maior) maior = valores[i];
        if (valores[i] < menor) menor = valores[i];
    }

    printf("Maior valor = %d\n", maior);
    printf("Menor valor = %d\n", menor);

    return 0;
}
