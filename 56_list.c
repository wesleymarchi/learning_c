/* Manipula uma lista de caracteres com opções de inserir e remover
 */

#include <stdio.h>
#include <stdlib.h>

// Estrutura auto-referenciada
struct listNode {
    char data;
    struct listNode *prox;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

void insert(LISTNODEPTR *, char);
char delete(LISTNODEPTR *, char);
int isEmpty(LISTNODEPTR); // Chamada "função predicada", não altera a lista
void printList(LISTNODEPTR);
void showMenu(void);

int main() {
    LISTNODEPTR startPtr = NULL;
    int op;
    char item;

    showMenu();
    printf("Insira uma opcao: ");
    scanf("%d", &op);

    while (op != 3) {
        switch (op) {
            case 1:
                printf("Insira um caractere: ");
                scanf(" %c", &item); // espaço antes de %c para ignorar '\n'
                insert(&startPtr, item);
                printList(startPtr);
                break;
            case 2:
                if (!isEmpty(startPtr)) {
                    printf("Insira o caractere para remocao: ");
                    scanf(" %c", &item);

                    if (delete(&startPtr, item)) {
                        printf("%c removido.\n", item);
                        printList(startPtr);
                    } else {
                        printf("%c nao encontrado!\n\n", item);
                    }
                } else {
                    printf("A lista esta vazia.\n\n");
                }
                break;
            default:
                printf("Escolha invalida!\n\n");
                showMenu();
                break;
        }
        printf("Insira uma opcao: ");
        scanf("%d", &op);
    }

    return 0;
}

void showMenu(void) {
    printf("Escolha uma opcao:\n"
           "1. Inserir\n"
           "2. Remover\n"
           "3. Finalizar\n");
}

// Inserir um novo valor na lista em ordem alfabética
// A Lista é uma ligação para o primeiro elemento, ao passar
// o endereço da lista cria um ponteiro para ponteiro
void insert(LISTNODEPTR *startPtr, char item) {
    LISTNODEPTR newPtr, prevPtr, currPtr;

    newPtr = malloc(sizeof(LISTNODE));  // aloca memória

    // se foi alocado memória
    if (newPtr != NULL) {
        newPtr->data = item; // atribui o item ao campo data
        newPtr->prox = NULL; // indica que o novo nó não aponta para lugar nenhum

        // Ponteiros utilizados para armazenar os locais do nó antes e depois do ponto de inserção
        prevPtr = NULL; // previous (anterior)
        currPtr = *startPtr; // current (atual); ponteiro para o início da lista

        // Verifica se currPtr é diferente de NULL e se o item (valor) é maior que o item atual de currPtr
        while (currPtr != NULL && item > currPtr->data) {
            prevPtr = currPtr; // atribui o atual para o anterior
            currPtr = currPtr->prox; // atribui o proximo para o atual
        }

        // Insere o novo nó no início
        if (prevPtr == NULL) {
            newPtr->prox = *startPtr;
            *startPtr = newPtr;
        } else {
            prevPtr->prox = newPtr;
            newPtr->prox = currPtr;
        }
    } else {
        printf("%c nao inserido. Sem memoria!\n", item);
    }
}

// Remove um item da lista
char delete(LISTNODEPTR *startPtr, char item) {
    LISTNODEPTR currPtr, prevPtr, tempPtr;

    if (*startPtr == NULL)
        return '\0';

    if (item == (*startPtr)->data) { // Remoção do primeiro item
        tempPtr = *startPtr;
        *startPtr = (*startPtr)->prox;
        free(tempPtr);
        return item;
    } else {
        prevPtr = *startPtr;
        currPtr = (*startPtr)->prox;

        while (currPtr != NULL && currPtr->data != item) {
            prevPtr = currPtr;
            currPtr = currPtr->prox;
        }

        if (currPtr != NULL) {
            tempPtr = currPtr;
            prevPtr->prox = currPtr->prox;
            free(tempPtr);
            return item;
        }
    }

    return '\0';
}

// Retorna 1 se a lista está vazia, 0 caso contrário
int isEmpty(LISTNODEPTR startPtr) {
    return startPtr == NULL; // 1 vazio
}

void printList(LISTNODEPTR currPtr) {
    if (currPtr == NULL) {
        printf("Lista vazia!\n\n");
    } else {
        printf("A lista: ");
        while (currPtr != NULL) {
            printf("%c --> ", currPtr->data);
            currPtr = currPtr->prox;
        }
        printf("NULL\n\n");
    }
}
