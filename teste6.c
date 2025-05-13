#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[30];
    int idade;
} Aluno;

int main() {
    FILE *fp = fopen("alunos.txt", "r");
    Aluno a;
    char busca[30];
    int encontrado = 0;

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("Digite o nome para buscar: ");
    scanf(" %[^\n]", busca); // Lê a string até encontrar \n

    while (fscanf(fp, "%s %d", a.nome, &a.idade) != EOF) {
        if (strcmp(a.nome, busca) == 0) {
            printf("Encontrado: %s - %d anos\n", a.nome, a.idade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Nome nao encontrado.\n");
    }

    fclose(fp);
    return 0;
}
