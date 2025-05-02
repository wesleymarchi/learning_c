/* Definindo um array como const para impedir modificações */

#include <stdio.h>

void tryModify(const int []);

int main() {
  int arr[] = { 1, 2, 3 };

  tryModify(arr);

  printf("%d %d %d\n", arr[0], arr[1], arr[2]);

  return 0;
}

void tryModify(const int arr[]) {
  for (int i = 0; i < 3; i++)
    arr[i] /= 2; // erro
}