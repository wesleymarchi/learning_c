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
                printf("Enter a char: ");
                scanf(" %c", &item);

                // CORREÇÃO: passar &tailPtr
                enqueue(&headPtr, &tailPtr, item);

                printQueue(headPtr);
                break;

            case 2:
                if (!isEmpty(headPtr)) {
                    item = dequeue(&headPtr, &tailPtr);
                    printf("%c dequeued.\n", item);
                    printQueue(headPtr);
                } else {
                    printf("Queue is empty.\n");
                }
                break;

            default:
                printf("Invalid option.\n\n");
                break;
        }

        showMenu();
        printf("Enter an option: ");
        scanf("%d", &op);
    }

    return 0;
}

void showMenu(void) {
    printf("\nEnter an option:\n"
           "1. Enqueue\n"
           "2. Dequeue\n"
           "3. Quit\n");
}

void enqueue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr, char item) {
    QUEUENODEPTR newPtr = malloc(sizeof(QUEUENODE));

    if (newPtr != NULL) {
        newPtr->data = item;
        newPtr->next = NULL;

        // CORREÇÃO: atualizar tailPtr quando a fila está vazia
        if (isEmpty(*headPtr)) {
            *headPtr = newPtr;
            *tailPtr = newPtr;
        } else {
            (*tailPtr)->next = newPtr;
            *tailPtr = newPtr;
        }
    } else {
        printf("Not enough space to allocate.\n");
    }
}

char dequeue(QUEUENODEPTR *headPtr, QUEUENODEPTR *tailPtr) {
    QUEUENODEPTR tempPtr = *headPtr;
    char item = tempPtr->data;

    *headPtr = (*headPtr)->next;

    // CORREÇÃO: quando a fila fica vazia, tail deve virar NULL
    if (*headPtr == NULL) {
        *tailPtr = NULL;
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
        printf("Queue: ");
        while (currentPtr != NULL) {
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->next;
        }
        printf("NULL\n");
    }
}
