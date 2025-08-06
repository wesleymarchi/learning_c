/* Verificar se uma pessoa é maior de idade */

#include <stdio.h>

int main() {
    int age;

    printf("Digite sua idade: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("Você eh maior de idade.\n");
    } else {
        printf("Você eh menor de idade.\n");
    }

    return 0;
}
