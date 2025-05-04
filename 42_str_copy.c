/* Copiando string com notação de array e notação de ponteiro com principio do privilegio minimo */

#include <stdio.h>

void copy1(char *, const char *);  // const: nenhuma função precisa da capacidade de modificar a string original
void copy2(char *, const char *);

int main() {
  char string1[10], *string2 = "Hello!", string3[10], string4[] = "Good bye!";

  copy1(string1, string2);
  printf("string1 = %s\n", string1);

  copy2(string3, string4);
  printf("string3 = %s\n", string3);

  return 0;
}

// Notação de array/subscrito
void copy1(char *str1, const char *str2) {
  for (int i = 0; str1[i] = str2[i]; i++);  // Copia um caractere por vez
}

// Notação de ponteiro
void copy2(char *str1, const char *str2) {
  for (; *str1 = *str2; str1++, str2++);  // Aritmética de ponteiros
}
