#include <stdio.h>

typedef struct {
    char nome[100];
    int idade;
    float altura;
} Pessoa;

int main() {
    Pessoa p;
    Pessoa *ptr = &p;

    printf("Nome: ");
    fgets(ptr->nome, 50, stdin);

    printf("Idade: ");
    scanf("%d", &ptr->idade);

    printf("Altura: ");
    scanf("%f", &ptr->altura);

    printf("Dados da pessoa");
    printf("\nNome: %s", ptr->nome);
    printf("\nIdade: %d", ptr->idade);
    printf("\nAltura: %.2f", ptr->altura);

    return 0;
}