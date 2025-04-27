/* Uma função recursiva chama a si mesma, direta ou indiretamente */

#include <stdio.h>

long fat(long);

int main() {
    int i;
    for (i = 1; i <= 5; i++)
        printf("%2d! = %1d\n", i, fat(i));

    return 0;
}

/* Funcao recursiva */
long fat(long n) {
    if (n <= 1)
        return 1;
    else
        return (n * fat(n - 1));
}