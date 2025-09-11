/* Regras de escopo, variável global, local e static */

#include <stdio.h>

void a(void); /* Prototipo de funcao */
void b(void);
void c(void);

int x = 1; /* global */

int main() {
    int x = 5; /* local */
    printf("x local no escopo externo de main eh %d\n", x);
    {
        /* novo escopo */
        int x = 7;
        printf("x local no escopo interno de main eh %d\n", x);
    }
    printf("x local no escopo externo de main eh %d\n", x);
    a(); /* a tem x local automatico */
    b(); /* b tem x local estatico */
    c(); /* c usa x global */
    a(); /* reinicializa x local automatico */
    b(); /* x local estatico conserva seu valor anterior */
    c(); /* x global tambem conserva seu valor */
    printf("x local em main eh %d\n", x);

    return 0;
}

void a(void) {
    int x = 25; /* inicializa sempre que a eh chamada */
    printf("\nx local em a eh %d depois de entrar em a\n", x);
    ++x;
    printf("x local em a eh %d antes de sair de a\n", x);
}

void b(void) {
    static int x = 50; /* inicializacao estatica */
    printf("\nx local estatico eh %d ao entrar em b\n", x);
    ++x;
    printf("x local estatico eh %d ao sair de b\n", x);
}

void c(void) {
    printf("\nx global eh %d ao entrar em c\n", x);
    x += 10;
    printf("x global eh %d ao sair de c\n", x);
}