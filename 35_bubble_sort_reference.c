/* Bubble Sort por referência
 * Devido ao escopo de função, swap não tem acesso a elementos individuais do array em calssBolha
 * Mas é necessário que swap tenha acesso aos elementos, pode-se passar cada elemento a swap por referencia
 * */

#include <stdio.h>
#define SIZE 10

// Realiza a ordenação do array
void classBolha(int *, int);

int main() {
  int arr[SIZE] = {10, 4, 5, 3, 2, 7, 9, 8, 6, 0};

  printf("Array original:\n");
  for (int i = 0; i < SIZE; i++)
    printf("%4d", arr[i]);

  classBolha(arr, SIZE);
  printf("\nArray ordenado:\n");
  for (int i = 0; i < SIZE; i++)
    printf("%4d", arr[i]);

  return 0;
}

void classBolha(int *arr, int size) {
  // Permuta/troca os valores: protótipo de função no escopo de classBolha restringe as chamadas de swap a partir de outras funções
  void swap(int *, int *);

  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
}

void swap(int *elPtr1, int *elPtr2) {
  int temp;

  temp = *elPtr1;
  *elPtr1 = *elPtr2;
  *elPtr2 = temp;
}