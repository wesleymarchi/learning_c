// Árvore de pesquisa binária

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct treeNode {
    struct treeNode *leftPtr;
    struct treeNode *rightPtr;
    int data;
};

typedef struct treeNode TREENODE;
typedef TREENODE *TREENODEPTR;

void insertNode(TREENODEPTR *, int);
void inOrder(TREENODEPTR);
void preOrder(TREENODEPTR);
void postOrder(TREENODEPTR);

int main() {
    int i, data;
    TREENODEPTR rootPtr = NULL;

    srand(time(NULL)); // para tentar inserir valores aleatórios de 0 a 14
    printf("Os numeros sao: \n");

    for (i = 1; i <= 10; i++) {
        data = rand() % 15;
        printf("%3d", data);
        insertNode(&rootPtr, data);
    }

    // preOrder
    printf("\n\npreOrder:\n");
    preOrder(rootPtr);

    //inOrder
    printf("\n\ninOrder:\n");
    inOrder(rootPtr);

    // postOrder
    printf("\n\npostOrder:\n");
    postOrder(rootPtr);

    return 0;
}

void insertNode(TREENODEPTR *treePtr, int value) {
    if (*treePtr == NULL) {
        *treePtr = malloc(sizeof(TREENODE));

        if (*treePtr != NULL) {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        } else {
            printf("%d nao inserido. sem memoria.\n", value);
        }
        return;
    }

    // inserção recursiva
    if (value < (*treePtr)->data) {
        insertNode(&((*treePtr)->leftPtr), value);
    } else if (value > (*treePtr)->data) {
        insertNode(&((*treePtr)->rightPtr), value);
    } else {
        printf("dub");
    }
}

void inOrder(TREENODEPTR treePtr) {
    if (treePtr != NULL) {
        inOrder(treePtr->leftPtr);
        printf("%3d", treePtr->data);
        inOrder(treePtr->rightPtr);
    }
}

void preOrder(TREENODEPTR treePtr) {
    if (treePtr != NULL) {
        printf("%3d", treePtr->data);
        preOrder(treePtr->leftPtr);
        preOrder(treePtr->rightPtr);
    }
}

void postOrder(TREENODEPTR treePtr) {
    if (treePtr != NULL) {
        postOrder(treePtr->leftPtr);
        postOrder(treePtr->rightPtr);
        printf("%3d", treePtr->data);
    }
}