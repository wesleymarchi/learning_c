/* Calcular a média de duas notas */

#include <stdio.h>

int main() {
    float n1, n2, m;

    printf("Digite a primeira nota: ");
    scanf("%f", &n1);

    printf("Digite a segunda nota: ");
    scanf("%f", &n2);

    m = (n1 + n2) / 2;

    if (m >= 70) {
        printf("Aprovado com media %.2f\n", m);
    } else {
        printf("Reprovado com media %.2f\n", m);
    }

    return 0;
}
