#include <stdio.h>

typedef struct {
    char nome[30];
    float nota1, nota2;
} Aluno;

float media(Aluno *a) {
    return (a->nota1 + a->nota2) / 2;
}

const char* situacao(float m) {
    return m >= 6 ? "Aprovado" : "Reprovado";  // operador ternário
}

int main() {
    Aluno alunos[3];
    for (int i = 0; i < 3; i++) {
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);  // Lê a string até encontrar \n

        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);

        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
    }

    for (int i = 0; i < 3; i++) {
        float m = media(&alunos[i]);
        printf("\n%s - Media: %.2f - %s\n", alunos[i].nome, m, situacao(m));
    }

    return 0;
}
