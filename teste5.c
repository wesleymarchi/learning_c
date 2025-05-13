#include <stdio.h>

typedef struct {
    char nome[30];
    int idade;
} Aluno;

int main() {
    FILE *fp = fopen("alunos.txt", "r");
    Aluno a;

    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fscanf(fp, "%s %d", a.nome, &a.idade) != EOF) {
        printf("Nome: %s - Idade: %d\n", a.nome, a.idade);
    }

    fclose(fp);
    return 0;
}
