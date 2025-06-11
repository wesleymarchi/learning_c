/* Pilha (stack) */

#include <stdio.h>
#include <stdlib.h>

struct stackNode {
    int data;
    struct stackNode *next;
};

typedef struct stackNode STACKNODE;
typedef STACKNODE *STACKNODEPTR;

void push(STACKNODEPTR *, int);
int pop(STACKNODEPTR *);
int isEmpty(STACKNODEPTR);
void printStack(STACKNODEPTR);
void showMenu(void);

int main() {
    STACKNODEPTR stackPtr = NULL;
    int op, value;

    showMenu();
    printf("\nEnter an option:\n");
    scanf("%d", &op);

    while (op != 3) {
        switch (op) {
            case 1:
                printf("Enter an integer:\n");
                scanf("%d", &value);
                push(&stackPtr, value);
                printStack(stackPtr);
                break;
            case 2:
                if (!isEmpty(stackPtr))
                    printf("Removed value: %d\n", pop(&stackPtr));
                printStack(stackPtr);
                break;
            default:
                printf("Invalid option!\n");
                showMenu();
                break;
        }
        printf("\nEnter an option: ");
        scanf("%d", &op);
    }

    return 0;
}

void showMenu(void) {
    printf("1. Push\n"
           "2. Pop\n"
           "3. Quit\n");
}

void push(STACKNODEPTR *stackPtr, int value) {
    STACKNODEPTR newNodePtr;

    newNodePtr = malloc(sizeof(STACKNODE));

    if (newNodePtr != NULL) {
        newNodePtr->data = value;
        newNodePtr->next = *stackPtr;
        *stackPtr = newNodePtr;
    } else {
        printf("Memory allocation error!\n");
    }
}

int pop(STACKNODEPTR *stackPtr) {
    STACKNODEPTR tempNodePtr;
    int poppedValue;

    tempNodePtr = *stackPtr;
    poppedValue = (*stackPtr)->data;
    *stackPtr = (*stackPtr)->next;
    free(tempNodePtr);

    return poppedValue;

}

void printStack(STACKNODEPTR stackPtr) {
    if (stackPtr == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack:");
        while (stackPtr != NULL) {
            printf("\n%d ", stackPtr->data);
            stackPtr = stackPtr->next;
        }
    }
}

int isEmpty(STACKNODEPTR stackPtr) {
    return (stackPtr == NULL);
}