#include <stdio.h>

typedef struct {
    char nome[30];
    int idade;
} Aluno;

int main() {
    FILE *fp = fopen("alunos.txt", "w");
    Aluno a;

    for (int i = 0; i < 3; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", a.nome);
        printf("Idade: ");
        scanf("%d", &a.idade);
        fprintf(fp, "%s %d\n", a.nome, a.idade);
    }

    fclose(fp);
    return 0;
}
