/* Calcular o IMC */

#include <stdio.h>

int main() {
    float p, a, imc;

    printf("Digite seu peso (em kg): ");
    scanf("%f", &p);

    printf("Digite sua altura (em metros): ");
    scanf("%f", &a);

    imc = p / (a * a);

    if (imc < 18.5) {
        printf("IMC: %.2f - Abaixo do peso\n", imc);
    } else if (imc < 25.0) {
        printf("IMC: %.2f - Peso normal\n", imc);
    } else if (imc < 30.0) {
        printf("IMC: %.2f - Sobrepeso\n", imc);
    } else {
        printf("IMC: %.2f - Obesidade\n", imc);
    }

    return 0;
}
