/* Ponteiros contêm endereços de memória, podendo ser inicializado com 0, NULL ou um endereço;
 * & (operador de ponteiro) retorna o endereço de seu operando;
 * * (operador de referência indireta) retorna o valor do objeto ao qual seu operando aponta
 */
#include <stdio.h>

int main() {
    int a;
    int *aPtr;  // aPtr eh um ponteiro para um inteiro

    a = 9;
    aPtr = &a;  // Atribui o endereco de a

    printf("O endereco de a eh %p\nO valor de aPtr eh %p\n\n", &a, aPtr);
    printf("O valor de a eh %d\nO valor de *aPtr eh %d\n\n", a, *aPtr);
    printf("Sabendo que * e & complementam-se mutuamente.\n&*aPtr = %p\n*&aPtr = %p\n", &*aPtr, *&aPtr);

    return 0;
}