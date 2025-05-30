/* Ordenando um array com bubble sort (classificação de bolha) */

#include <stdio.h>

void bubbleSort(int [], int);

int main() {
  int arr[] = {5, 2, 7, 1, 0, 9, 10, 5, -1, 8};
  int size = 10;

  printf("Array original: \n");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  bubbleSort(arr, size);

  printf("\nArray ordenado: \n");
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);

  return 0;
}

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++)
    for (int j = 0; j < size - i - 1; j++)
      // troca os elementos
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      } // {5, 2, 7, 1, 0, 9, 10, 5, -1, 8};
}