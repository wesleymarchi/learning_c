/* Operador unário sizeof determina o tamanho em bytes de um array ou qualquer outro tipo de dado */

#include <stdio.h>

int main() {
  int arr[10]; // um inteiro possui 4 bytes

  printf("%d bytes\n", sizeof(arr));  // Tamanho em bytes
  printf("%d elementos\n", sizeof(arr) / sizeof(int));  // Determina o número de elementos do array

  return 0;
}