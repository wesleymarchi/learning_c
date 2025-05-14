/* Grava dados no arquivo utilizando funções fseek e fwrite para armazenar dados em determinados locais
 * do arquivo.
 * fseek() define o ponteiro de posição do arquivo em um determinado local e fwrite() grava os dados
 *
 */

#include <stdio.h>

struct dadosCliente {
    int numConta;
    char nome[20];
    char sobrenome[20];
    float saldo;
};

int main() {
    struct dadosCliente cliente;
    FILE *cfPtr;

    if ((cfPtr = fopen("credito.dat", "r+")) == NULL) {  // modo leitura/gravação
        printf("O arquivo nao pode ser aberto.\n");
    } else {
        printf("Insira o numero da conta (1 a 100, 0 para encerrar)\n");
        scanf("%d", &cliente.numConta);

        while (cliente.numConta != 0) {
            printf("Insira o nome, sobrenome e saldo\n");
            scanf("%s %s %f", &cliente.nome, &cliente.sobrenome, &cliente.saldo);

            // Posiciona o ponteiro de posição de arquivo no inicio do registro, a expressão é chamado de offset.
            // O número da conta vai de 1 a 100, mas as posições de bytes no arquivo inicia-se com 0
            // SEEK_SET indica que a pesquisa começa no inicio do arquivo
            // Basicamente fseek() acessa diretamente um registro
            fseek(cfPtr, (cliente.numConta - 1) * sizeof(struct dadosCliente), SEEK_SET);
            // 1 refere-se a gravar um objeto isolado equivalente a 1 objeto de um array
            fwrite(&cliente, sizeof(struct dadosCliente), 1, cfPtr);

            printf("Insira o numero da conta\n");
            scanf("%d", &cliente.numConta);
        }
    }

    fclose(cfPtr);

    return 0;
}