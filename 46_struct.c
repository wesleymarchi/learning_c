/* Estrutura e operadores de membro e ponteiro */

#include <stdio.h>

struct carta {
  char *face;
  char *naipe;
};

int main() {
  struct carta c;
  struct carta *cPtr;

  c.face = "As";
  c.naipe = "Espadas";

  cPtr = &c;
  printf("%s%s%s\n%s%s%s\n%s%s%s\n", c.face, " de ", c.naipe,
      cPtr->face, " de ", cPtr->naipe,
      (*cPtr).face, " de ", (*cPtr).naipe);

  return 0;
}