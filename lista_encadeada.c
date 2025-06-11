// Manipulação de lista encadeada

#include <stdio.h>
#include <stdlib.h>

// Estrutura auto-referenciada
struct listNode {
    char data;
    struct listNode *prox;
};

typedef struct listNode LISTNODE;
typedef LISTNODE *LISTNODEPTR;

// prototipos de função
void insert(LISTNODEPTR *, char);
char delete(LISTNODEPTR *, char);
int isEmpty(LISTNODEPTR); // função predicada: ela não altera a lista
void printList(LISTNODEPTR);
void showMenu(void);

int main() {
    LISTNODEPTR starPtr = NULL;
    int op;
    char item;

    showMenu();
    printf("Insira uma opcao: ");
    scanf("%d", &op);

    while (op != 3) {

    }

    return 0;
}

void showMenu(void) {
    printf("Escolha uma opcao: \n"
           "1. Insert\n"
           "2. Delete\n"
           "3. Quit\n");
}

// inserir um novo valor na lista em ordem alfabetica
// A lista é uma ligação para o primeiro elemento
// a passar o endereço da lista cria-se um ponteiro para ponteiro
void insert(LISTNODEPTR *startPtr, char item) {
    LISTNODEPTR newPtr, prevPtr, currPtr;

    newPtr = malloc(sizeof(LISTNODE));

    // se foi alocado memoria
    if (newPtr != NULL) {
        newPtr->data = item;
        newPtr->prox = NULL; // nao aponta para lugar algum

        prevPtr = NULL;
        currPtr = *startPtr;

        // verifica se currPtr é diferente de NULL, e se o valor (item) é maior que currPtr->data
        while (currPtr != NULL && item > currPtr->data) {
            prevPtr = currPtr;
            currPtr = currPtr->prox;
        }

        // Insere o novo nó no inicio
        if (prevPtr == NULL) {
            newPtr->prox = *startPtr;
            *startPtr = newPtr;
        } else {
            prevPtr->prox = newPtr;
            newPtr->prox = currPtr;
        }
    } else {
        printf("ERROR!\n");
    }
}


































