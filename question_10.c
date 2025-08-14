#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, palpite, tentativas = 0;

    srand(time(NULL));
    n = rand() % 50 + 1; // Número aleatório de 1 a 50

    printf("Tente adivinhar o numero de 1 a 50. Voce tem 5 tentativas.\n");

    for(tentativas = 1; tentativas <= 5; tentativas++) {
        printf("Tentativa %d: ", tentativas);
        scanf("%d", &palpite);

        if(palpite == n)
            break;
        else if(palpite > n)
            printf("Menor!\n");
        else
            printf("Maior!\n");
    }

    switch(tentativas) {
        case 1:
            printf("Incrivel! Acertou de primeira!\n");
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            if(palpite == n)
                printf("Parabens! Voce acertou em %d tentativas.\n", tentativas);
            else
                printf("Nao foi dessa vez! O numero era %d.\n", n);
            break;
        default:
            printf("Nao foi dessa vez! O numero era %d.\n", n);
    }

    return 0;
}
