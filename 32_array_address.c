/* Exibe o endereço de um array a partir do seu nome ou posição inicial
 * %p imprime o endereço
 * numeros hexadecimais (base 16) consiste nos digitos 0 a 9 e letras A a F
 * */

#include <stdio.h>

int main() {
  char arr[5];

  printf("    arr = %p\n&arr[0] = %p\n", arr, &arr[0]); // arr[0] contém o endereço do array

  return 0;
}