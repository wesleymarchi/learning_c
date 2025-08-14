#include <stdio.h>

int main() {
    int estoque1 = 0, estoque2 = 0, estoque3 = 0;
    int op, qtd;

    while(1) {
        printf("\n=== CONTROLE DE ESTOQUE ===\n");
        printf("1 - Adicionar produto\n");
        printf("2 - Remover produto\n");
        printf("3 - Mostrar estoque\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);

        if(op == 4)
            break;

        switch(op) {
            case 1:
                printf("Escolha o produto (1, 2 ou 3): ");
                scanf("%d", &op);
                printf("Quantidade: ");
                scanf("%d", &qtd);

                if(op == 1)
                    estoque1 += qtd;
                else if(op == 2)
                    estoque2 += qtd;
                else if(op == 3)
                    estoque3 += qtd;
                else
                    printf("Produto invalido!\n");
                break;

            case 2:
                printf("Escolha o produto (1, 2 ou 3): ");
                scanf("%d", &op);
                printf("Quantidade: ");
                scanf("%d", &qtd);

                if(op == 1 && estoque1 >= qtd)
                    estoque1 -= qtd;
                else if(op == 2 && estoque2 >= qtd)
                    estoque2 -= qtd;
                else if(op == 3 && estoque3 >= qtd)
                    estoque3 -= qtd;
                else
                    printf("Quantidade invalida ou produto inexistente!\n");
                break;

            case 3:
                printf("Produto 1: %d\nProduto 2: %d\nProduto 3: %d\n", estoque1, estoque2, estoque3);
                break;

            default:
                printf("Opcao invalida!\n");
        }
    }

    return 0;
}
