/* Converte letras minusculas para maiusculas */

#include <stdio.h>

void toUpper(char *);

int main() {
    char string[] = "123";

    printf("A string antes da conversao: %s\n", string);

    toUpper(string);

    printf("A string depois da conversao: %s\n", string);

    return 0;
}

void toUpper(char *s) {
    while (*s != '\0') {
        if (*s >= 'a' && *s <= 'z')
            *s -= 32; // Converte para letra maiuscula ASCII: qual a diferença na tabela ASCII entre as colunas?

        ++s; // Incremento para o próximo caractere
    }
}