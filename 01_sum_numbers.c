/* Soma dois números inteiros */

#include <stdio.h>  // Header

int main() {
    int x, y, sum;    // Declarando variáveis

    printf("Insira o primeiro numero:\n");  // Exibe uma mensagem na tela
    // scanf: obtém um valor fornecido pelo usuário (teclado)
    // Esta função possui dois "argumentos": "%d" (string de controle de formato) que indica o tipo de dado
    // que deve ser fornecido, sendo o "%d" um "especificador de conversão" indicando um inteiro (d = decimal integer)
    // & (operador de endereço): combinado com o nome da variável, diz o local na memória onde a variável está armazenada
    scanf("%d", &x);

    printf("Insira o segundo numero:\n");
    scanf("%d", &y);

    sum = x + y;    // atribui o resultado da soma entre x e y para a variável "sum"

    printf("Resultado da soma: %d\n", sum); // Exibe o resultado

    return 0;
}