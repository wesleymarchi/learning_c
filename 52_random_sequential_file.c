/* Programa de acesso aleatório */

#include <stdio.h>

struct dadosCliente {
    int numConta;
    char nome[20];
    char sobrenome[20];
    float saldo;
};

int main() {
    int i;
    struct dadosCliente clienteNulo = {0 , "", "", 0.0};
    FILE *cfPtr;

    if ((cfPtr = fopen("credito.dat", "w")) == NULL) {
        printf("O arquivo nao pode ser aberto\n");
    } else {
        for (i = 1; i <= 100; i++)
            // Faz com que a estrutura clienteNulo (com tamanho x) seja gravada no arquivo apontado por cfPtr
            fwrite(&clienteNulo, sizeof(struct dadosCliente), 1, cfPtr);

        fclose(cfPtr);
    }

    return 0;
}