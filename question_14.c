/* Exibe os elemenos da diagonal principal */

#include <stdio.h>

int main() {
    int matriz[3][3];

    printf("Digite os elementos da matriz 3x3:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Diagonal principal:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");

    return 0;
}
