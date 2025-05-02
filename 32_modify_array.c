/* Passando arrays e elementos para uma função */

#include <stdio.h>
#define SIZE 5

void modificaArr(int [], int);
void modificaElem(int);

int main() {
  int arr[SIZE] = {0, 1, 2, 3, 4};

  printf("arr original (referencia)\n");
  for (int i = 0; i <= SIZE - 1; i++)
    printf("%3d", arr[i]);

  printf("\n");

  modificaArr(arr, SIZE); // referencia

  printf("Valores modificados:\n");
  for (int i = 0; i <= SIZE - 1; i++)
    printf("%3d", arr[i]);

  printf("\nPassando elemento do arr por valor/copia\nO valor de arr[3] eh %d\n", arr[3]);

  modificaElem(arr[3]); // copia

  printf("O valor de arr[3] eh %d\n", arr[3]);

  return 0;
}

void modificaArr(int arr[], int size) {
  for (int i = 0; i < size; i++)
    arr[i] *= 2;
}

void modificaElem(int el) {
  printf("Valor modificado no escopo da funcao eh: %d\n", el *=2);
}