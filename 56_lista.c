#include <stdio.h>
#include <stdlib.h>

// Estrutura auto-referenciada
struct listaNo {
    char data;
    struct listaNo *prox;
};

typedef struct listaNo *LISTA;
typedef LISTA *LISTAPTR;

void insert(LISTAPTR, char);
char delete(LISTAPTR, char);
int isEmpty(LISTA);
void printLista(LISTA);
void showMenu(void);

int main() {
    LISTA startPtr = NULL;
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
                printLista(startPtr);
                break;

            case 2:
                if (!isEmpty(startPtr)) {
                    printf("Insira o caractere para remocao: ");
                    scanf(" %c", &item);

                    if (delete(&startPtr, item)) {
                        printf("%c removido.\n", item);
                        printLista(startPtr);
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
void insert(LISTAPTR startPtr, char item) {
    LISTA newPtr, prevPtr, currPtr;

    newPtr = malloc(sizeof(struct listaNo));  // aloca memória

    if (newPtr != NULL) {
        newPtr->data = item;
        newPtr->prox = NULL;

        prevPtr = NULL;
        currPtr = *startPtr;

        while (currPtr != NULL && item > currPtr->data) {
            prevPtr = currPtr;
            currPtr = currPtr->prox;
        }

        if (prevPtr == NULL) {  // Inserção no início
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
char delete(LISTAPTR startPtr, char item) {
    LISTA currPtr, prevPtr, tempPtr;

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
int isEmpty(LISTA startPtr) {
    return startPtr == NULL;
}

void printLista(LISTA currPtr) {
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
