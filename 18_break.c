/* Break quebra o fluxo principal
 * continue segue para o proximo fluxo, impedindo apenas as proximas instruções de executarem
 * Teste com break e continue
 */

#include <stdio.h>

int main() {
    int k;

    for (k = 1; k <= 5; k++) {
      if (k == 3)
        continue; // altere para break/continue e veja a diferença

      printf("%d\n", k);
    }

    printf("\nSaida do loop em k = %d\n", k);

    return 0;
}