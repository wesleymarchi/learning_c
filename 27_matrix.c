/* Define uma matriz 3x3, utlizando array bidimenssional*/

#include <stdio.h>

#define LINE 3
#define COLUNM 3

int main() {
    int matrix[LINE][COLUNM];

    // Preenchendo a matriz com valores do usuário
    printf("Digite os elementos da matriz %dx%d:\n", LINE, COLUNM);
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLUNM; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Exibindo a matriz
    printf("\nMatriz inserida:\n");
    for (int i = 0; i < LINE; i++) {
        for (int j = 0; j < COLUNM; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
