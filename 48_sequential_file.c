/* Criando um arquivo de acesso sequencial
 * Cria um arquivo simples usado para recebimento de contas para controle de quantias devidas por clientes devedores
 * Para cada cliente, o programa obtem um numero de conta, nome do cliente e o saldo do cliente (saldo devedor)
 * O número da conta é usado como campo-chave dos registros, o arquivo será criado e mantido conforme a ordem dos nºs
 * Em um sistema mais robusto, seria possivel inserir uma "feature" de ordenação, os registros seriam ordenados e gravados
 *
 * Para criar arquivos ou eliminar arquivos antes da gravação: w
 * Para ler um arquivo existente: r
 * Para adicionar registros ao final do arquivo existente: a
 *
 *  */

#include <stdio.h>

int main() {
  int conta;
  char nome[40];
  float saldo;
  FILE *cfPtr; // Ponteiro para FILE

  // Abre o arquivo clientes.dat para escrita
  // Se o arquivo não existe, é criado; caso o arquivo existe e é aberto para gravação (w), o conteúdo é eliminado
  if ((cfPtr = fopen("clientes.dat", "w")) == NULL) { // fopen(): nome do arquivo, e modo de abertura
    printf("O arquivo não pode ser aberto.\n");
    return 1;
  }

  printf("Digite a conta, o nome e o saldo.\n");
  printf("Use Ctrl+D (Linux/Mac) ou Ctrl+Z (Windows) para encerrar.\n");
  printf("? ");

  // Loop de leitura segura usando scanf
  while (scanf("%d %39s %f", &conta, nome, &saldo) == 3) {
    fprintf(cfPtr, "%d %s %.2f\n", conta, nome, saldo);  // semelhante ao printf, mas recebe um ponteiro para arq
    printf("? ");
  }

  fclose(cfPtr);  // fecha o arquivo
  printf("Dados gravados com sucesso em 'clientes.dat'.\n");

  return 0;
}