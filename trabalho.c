#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARQ "estoque.txt"

typedef struct {
    int codigo;
    char tipo[30];
    char marca[30];
    char cor[20];
    int tamanho;
    int setor;
    int arara;
} Item;

// Funções
void mostrarItens();
void inserirItem();
void excluirItem();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int op;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Mostrar Itens\n");
        printf("2. Inserir Item\n");
        printf("3. Excluir Item\n");
        printf("0. Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        getchar(); // Limpar buffer

        switch(op) {
            case 1: mostrarItens(); break;
            case 2: inserirItem(); break;
            case 3: excluirItem(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
}

// Função para mostrar o conteúdo do arquivo
void mostrarItens() {
    FILE *f = fopen(ARQ, "r");
    if (!f) {
        printf("Arquivo nao encontrado.\n");
        return;
    }

    char linha[150];
    while (fgets(linha, sizeof(linha), f)) {
        printf("%s", linha);
    }
    fclose(f);
}

// Função para inserir um novo item no final do arquivo
void inserirItem() {
    Item item;
    printf("Setor (numero): ");
    scanf("%d", &item.setor);
    printf("Arara (numero): ");
    scanf("%d", &item.arara);
    printf("Codigo: ");
    scanf("%d", &item.codigo);
    getchar(); // limpar buffer

    printf("Tipo de vestuario: ");
    fgets(item.tipo, sizeof(item.tipo), stdin);
    item.tipo[strcspn(item.tipo, "\n")] = 0;

    printf("Marca: ");
    fgets(item.marca, sizeof(item.marca), stdin);
    item.marca[strcspn(item.marca, "\n")] = 0;

    printf("Cor: ");
    fgets(item.cor, sizeof(item.cor), stdin);
    item.cor[strcspn(item.cor, "\n")] = 0;

    printf("Tamanho: ");
    scanf("%d", &item.tamanho);

    // Abrir para leitura e ver se já existe Sx e Ax
    FILE *f = fopen(ARQ, "a");
    if (!f) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(f, "\nS%d\nA%d\n", item.setor, item.arara);
    fprintf(f, "%d, %s, %s, %s, %d\n", item.codigo, item.tipo, item.marca, item.cor, item.tamanho);
    fclose(f);

    printf("Item inserido com sucesso!\n");
}

// Função para excluir item por código (cria arquivo temporário)
void excluirItem() {
    int cod;
    printf("Digite o codigo do item a excluir: ");
    scanf("%d", &cod);

    FILE *f = fopen(ARQ, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!f || !temp) {
        printf("Erro ao abrir os arquivos.\n");
        return;
    }

    char linha[150];
    int encontrado = 0;

    while (fgets(linha, sizeof(linha), f)) {
        int codigoLinha;
        if (sscanf(linha, "%d,", &codigoLinha) == 1 && codigoLinha == cod) {
            encontrado = 1;
            continue; // Pula a linha do item
        }
        fputs(linha, temp);
    }

    fclose(f);
    fclose(temp);

    remove(ARQ);
    rename("temp.txt", ARQ);

    if (encontrado)
        printf("Item removido com sucesso.\n");
    else
        printf("Item nao encontrado.\n");
}
