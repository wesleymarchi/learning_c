#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor;  // ponteiro para o vetor
    int n, i;

    printf("Quantos numeros voce deseja armazenar? ");
    scanf("%d", &n);

    // Aloca memória dinamicamente para n inteiros
    // malloc retorna um void* (ponteiro genérico), precisamos dizer ao compilador que queremos um int* (ponteiro para inteiro).
    vetor = (int *)malloc(n * sizeof(int));

    // Verifica se a alocação foi bem-sucedida
    if (vetor == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    // Lê os valores
    for (i = 0; i < n; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Exibe os valores
    printf("Voce digitou:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(vetor);

    return 0;
}
