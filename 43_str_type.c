/* isdigit(): determina se o caractere é um digito;
 * isalpha(): letra maiuscula ou minuscula
 * isalnum(): verifica se é um digito ou letra
 * islower(): verifica se eh letra minuscula
 * isupper(): verifica se eh letra maiuscula
 * */

#include <stdio.h>
#include <ctype.h>

int main() {
  printf("%s\n%s%s\n%s%s\n\n", "isdigit(): ",
         isdigit('9') ? "9 eh um " : "9 nao eh um ", "digito",
         isdigit('@') ? "@ eh um " : "@ nao eh um ", "digito"); // Operador ternario: 0 (falso)

  printf("%s\n%s%s\n%s%s\n\n", "isalpha(): ",
         isalpha('A') ? "A eh uma " : "A nao eh uma ", "letra",
         isalpha('@') ? "@ eh uma " : "@ nao eh uma ", "letra");

  printf("%s\n%s%s\n%s%s\n\n", "isalnum(): ",
         isalnum('A') ? "A eh um " : "A nao eh um ", "digito ou letra",
         isalnum('9') ? "9 eh um " : "9 nao eh um ", "digito ou letra");

  printf("%s\n%s%s\n%s%s\n\n", "islower(): ",
         islower('A') ? "A eh uma " : "A nao eh uma ", "letra minuscula",
         islower('b') ? "b eh uma " : "b nao eh uma ", "letra minuscula");

  printf("%s\n%s%s\n%s%s\n\n", "isupper(): ",
         isupper('A') ? "A eh uma " : "A nao eh uma ", "letra maiuscula",
         isupper('b') ? "b eh uma " : "b nao eh uma ", "letra maiuscula");

  return 0;
}