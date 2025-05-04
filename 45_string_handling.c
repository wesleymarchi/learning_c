/* Manipulação de strings
 * strcpy(): copia str2 para array s1, retorna s1
 * strncpy(): copia no máximo n caracteres de s2 para s1
 * strcat(): concatena s2 a s1 (desafio utilizar a função)
 * strncat(): concatena no maximo n caracteres de s2 a s1 (desafio utilizar a função)
 * */

#include <stdio.h>
#include <string.h>

int main() {
  char x[] = "hello world";
  char y[20], z[6];

  printf("%s%s\n%s%s\n",
         "x: ", x,
         "y: ", strcpy(y, x));

  strncpy(z, x, 5);
  z[5] = '\0';

  printf("z: %s\n", z);

  return 0;
}
