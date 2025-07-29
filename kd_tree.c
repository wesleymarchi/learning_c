#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    int x, y;
} PONTO;

typedef struct kdnode {
    PONTO ponto;
    struct kdnode *esq, *dir;
} KDNODE;

// Função para criar um novo nó KD
KDNODE* novoNo(PONTO p) {
    KDNODE* node = (KDNODE*)malloc(sizeof(KDNODE));
    node->ponto = p;
    node->esq = node->dir = NULL;
    return node;
}

// Inserção na árvore KD
KDNODE* inserir(KDNODE* raiz, PONTO p, unsigned depth) {
    if (raiz == NULL)
        return novoNo(p);

    unsigned cd = depth % 2; // Alterna eixo: 0=x, 1=y de comparação em cada nível

    if ((cd == 0 && p.x < raiz->ponto.x) || (cd == 1 && p.y < raiz->ponto.y))
        raiz->esq = inserir(raiz->esq, p, depth + 1);
    else
        raiz->dir = inserir(raiz->dir, p, depth + 1);

    return raiz;
}

// Impressão em pré-ordem
void preOrdem(KDNODE *raiz) {
    if (raiz != NULL) {
        printf("(%d, %d)\n", raiz->ponto.x, raiz->ponto.y);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

int main() {
    KDNODE *raiz = NULL;
    PONTO pontos[] = {{3,6}, {17,15}, {13,15}, {6,12}, {9,1}, {2,7}, {10,19}};
    int n = sizeof(pontos) / sizeof(pontos[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, pontos[i], 0);

    printf("Pre-Ordem da arvore KD construida:\n");
    preOrdem(raiz);

    return 0;
}
