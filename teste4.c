#include <stdio.h>
#include <string.h>

#define QTD_ALUNOS 3

typedef struct {
    char nome[50];
    int idade;
} Aluno;

int main() {
    FILE *fp = fopen("alunos.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo");
        return 1;
    }

    Aluno a;

    for (int i = 0; i < QTD_ALUNOS; i++) {
        printf("Aluno %d\n", i + 1);

        printf("Nome: ");
        fgets(a.nome, sizeof(a.nome), stdin);
        a.nome[strcspn(a.nome, "\n")] = '\0'; // Remove o '\n' do final, pois fgets() o inclui

        printf("Idade: ");
        scanf("%d", &a.idade);
        getchar(); // Limpa o '\n' deixado pelo scanf

        fprintf(fp, "%s %d\n", a.nome, a.idade);
    }

    fclose(fp);
    printf("Dados salvos com sucesso em 'alunos.txt'.\n");

    return 0;
}
