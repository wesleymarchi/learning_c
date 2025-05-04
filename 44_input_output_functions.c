/* getchar(): obtem o proximo caractere de entrada e retorna um inteiro;
 * gets(): obtem caracteres para um array até que encontre o caractere de nova linha ou de fim de arquivo.
 * putchar(): imprime caracteres
 * puts(): imprime string seguida de nova linha
 * */

#include <stdio.h>

int main() {
  char str[50];
  char txt[50];
  char c;
  int i = 0;
  void reverse(char *);

  printf("Insira um texto: \n");
  gets(str);

  printf("\nO reverso eh: \n");
  reverse(str);

  puts("\nDigite um texto: ");
  while ((c = getchar()) != '\n')
    txt[i++] = c;

  txt[i] = '\0';  // Null ao fim da string
  puts("\nO texto digitado foi: ");
  puts(txt);

  return 0;
}

void reverse(char *s) {
  if (s[0] == '\0') {
    return;
  } else {
    reverse(&s[1]);
    putchar(s[0]);
  }
}