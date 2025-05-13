#include <stdio.h>

typedef struct {
    char nome[30];
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto produtos[5];
    float soma = 0;
    int i, maiorIndex = 0;

    for (i = 0; i < 5; i++) {
        printf("\nProduto %d\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Preco: ");
        scanf("%f", &produtos[i].preco);
        printf("Quantidade: ");
        scanf("%d", &produtos[i].quantidade);
        soma += produtos[i].preco;
        if (produtos[i].preco > produtos[maiorIndex].preco)
            maiorIndex = i;
    }

    printf("\nProduto mais caro: %s (R$ %.2f)\n", produtos[maiorIndex].nome, produtos[maiorIndex].preco);
    printf("Media de preco: R$ %.2f\n", soma / 5);
    return 0;
}
