/* Estrutura de controle aninhada */

#include <stdio.h>

int main() {
    int aprovados = 0, reprovados = 0, k = 0, resultado;

    while (k < 3) {
      printf("Insira um resultado (1=Aprovado, 2=Reprovado):\n");
      scanf("%d", &resultado);

      if (resultado == 1)
        aprovados++;
      else
        reprovados++;

      k++; // Operador de pós-incremento
    }

    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);

    return 0;
}