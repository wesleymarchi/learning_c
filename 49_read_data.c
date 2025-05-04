/* Ler dados de um arquivo
 * r: abre para leitura
 * w: cria arquivo para gravação
 * a: abre ou cria um arquivo para gravação no final do arquivo
 * r+: leitura e gravação
 * w+: cria arquivo para atualização
 * a+: abre ou cria arquivo para atualização, gravação feita no final do arquivo
 */

#include <stdio.h>

int main() {
  int conta;
  char nome[40];
  float saldo;
  FILE *cfPtr;

  if ((cfPtr = fopen("clientes.dat", "r")) == NULL) {
    printf("O arquivo nao pode ser aberto.\n");
  } else {
    printf("%-10s%-13s%s\n", "Conta", "Nome", "Saldo");

    // Lê os dados enquanto fscanf retornar 3 itens corretamente lidos
    while (fscanf(cfPtr, "%d%s%f", &conta, nome, &saldo) == 3) {
      printf("%-10d%-13s%7.2f\n", conta, nome, saldo);
    }

    fclose(cfPtr);
  }

  return 0;
}