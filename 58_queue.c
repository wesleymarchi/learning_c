/* Fila (Queue) */

#include <stdio.h>
#include <stdlib.h>

struct queueNode {
    char data;
    struct queueNode *next;
};

typedef struct queueNode QUEUENODE;
typedef QUEUENODE *QUEUENODEPTR;

void printQueue(QUEUENODEPTR);
int isEmpty(QUEUENODEPTR);
char dequeue(QUEUENODEPTR *, QUEUENODEPTR *);
void enqueue(QUEUENODEPTR *, QUEUENODEPTR *, char);
void showMenu(void);

int main() {
    QUEUENODEPTR headPtr = NULL, tailPtr = NULL;
    int op;
    char item;

    showMenu();
    printf("Enter an option: ");
    scanf("%d", &op);

    while (op != 3) {
        switch (op) {
            case 1:
                printf("Enter an char: ");
                scanf(" %c", &item);
                enqueue(&headPtr, tailPtr, item);
                printQueue(headPtr);
                break;
            case 2:
                if (!isEmpty(headPtr)) {
                    item = dequeue(&headPtr, &tailPtr);
                    printf("%c dequeue.\n", item);
                    printQueue(headPtr);
                    break;
                }
            default:
                printf("Invalid option.\n\n");
                showMenu();
                break;
        }
        printf("Enter an option: ");
        scanf("%d", &op);
    }

    return 0;
}

void showMenu(void) {
    printf("Enter an option:\n"
           "1. Enqueue\n"
           "2. Dequeue\n"
           "3. Quit\n");
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, char item) {
    QUEUENODEPTR newPtr;

    newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL) {
        newPtr->data = item;
        newPtr->next = NULL;

        if (isEmpty(*headPtr)) {
            *headPtr = newPtr;
        } else {
            (*tailPtr)->next = newPtr;
            *tailPtr = newPtr;
        }
    } else {
        printf("No se enough space to allocate.\n");
    }
}

char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr) {
    QUEUENODEPTR tempPtr;
    char item;

    item = (*headPtr)->data;
    tempPtr = *headPtr;
    *headPtr = (*headPtr)->next;

    if (*headPtr == NULL) {
        tailPtr = NULL;
    }

    free(tempPtr);

    return item;
}

int isEmpty(QUEUENODEPTR headPtr) {
    return headPtr == NULL;
}

void printQueue(QUEUENODEPTR currentPtr) {
    if (currentPtr == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue: \n");

        while (currentPtr != NULL) {
            printf("%c-->", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        printf("\n");
    }
}