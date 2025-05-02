/* Acessando elementos com notações */

#include <stdio.h>

int main() {
  int i, offset, arr[] = {1, 2, 3, 4};
  int *arrPtr = arr;  // Aponta para arr

  printf("Notacao subscrito:\n");
  for (i = 0; i < 4; i++)
    printf("arr[%d] = %d\n", i, arr[i]);

  printf("\nNotacao ponteiro offset:\n");
  for (offset = 0; offset < 4; offset++)
    printf("*(arr + %d) = %d\n", offset, *(arr + offset));

  printf("\nNotacao subscrito de ponteiro:\n");
  for (i = 0; i < 4; i++)
    printf("arrPtr[%d] = %d\n", i, arrPtr[i]);

  printf("\nNotacao ponteiro offset:\n");
  for (offset = 0; offset < 4; offset++)
    printf("*(arrPtr + %d) = %d\n", offset, *(arrPtr + offset));

  return 0;
}