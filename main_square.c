/* Função principal */

#include <stdio.h>
#include "square.h"

int main() {
  int n = 4;
  float side = 5.5;

  printf("Square of %d = %d\n", n, square_int(n));
  printf("Square of %d = %.2f\n", n, square_float((float)n));
  printf("Area of square %.2f = %.2f\n", side, area_of_square(side));

  return 0;
}