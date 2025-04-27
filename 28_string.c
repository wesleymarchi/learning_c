/* Todas as strings em C terminam com o caractere nulo (\0)
 * Ao utilizar scanf, ao lidar com array, não é necessário utilizar &
* pois o nome do array já representa o endereço de memória
 * */

#include <stdio.h>

int main() {
    char string1[6], string2[] = "string literal";
    int i;

    printf("Entre com uma string: ");
    scanf("%s", string1); // Necessário limitar o tamanho da entrada (por conta do caractere nulo)

    printf("string1 eh: %s\nstring2 eh: %s\n", string1, string2);

    for (i = 0; string1[i] != '\0'; i++)
        printf("%c", string1[i]); // %c destinado a cada caractere

    printf("\n");

    return 0;
}