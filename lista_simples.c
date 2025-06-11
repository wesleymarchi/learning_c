#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef int TData;


struct TNo{
    TData data;
    struct TNo * prox;
};

typedef struct TNo TNo;

void insertList(TNo **, TData);
int removeList(TNo **, TData);
void printAll(TNo *);
void destroy(TNo **);
void destroyRecursive(TNo **);

int main(){

    TNo * head = NULL;

    printf("Numbers: \n");
    insertList(&head,5);
    insertList(&head,55);
    insertList(&head,-20);
    insertList(&head,33);
    printAll(head);
    printf("\n");

    printf("\nRemove: ");
    removeList(&head,5);
    printf("\n");

    printAll(head);

    printf("\nDestroy: ");
    //printAllRecursive(head);
    destroyRecursive(&head);
}

//inseri um novo elemento ao final da lista
void insertList(TNo ** head, TData dataParam){
    TNo * newNo = (TNo *) malloc(sizeof(TNo));

    //(*newNo).data = data;
    newNo->data = dataParam;
    newNo->prox = NULL;

    if (*head == NULL) {
        *head = newNo;
    }else{
        TNo * pAux = *head;
        while (pAux->prox != NULL){
            pAux = pAux->prox;
        }
        pAux->prox = newNo;
    }
}

//busca o elemento que possui o dado igual ao passado por parametro
//se encontrar remove da lista, verificar se eh head
//retornar zero se nao achar e 1 se encontrar
int removeList(TNo ** head, TData data){
    TNo * pAnt = *head;
    TNo * pProx = *head;
    while ((pProx != NULL) && (pProx->data != data)){
        pAnt = pProx;
        pProx = pProx->prox;
    }
    if (pProx != NULL){
        if (pProx == *head){
            *head = pProx->prox;
        } else {
            pAnt->prox = pProx->prox;
        }
        pAnt->prox = pProx->prox;
        free(pProx);
        return 1; //eh interrompida no return
    }
    return 0;
}

void printAll(TNo * head){
    TNo * pAux = head;
    while (pAux != NULL){
        printf("\n%i",pAux->data);
        pAux = pAux->prox;
    }
}

//void printAllRecursive(TNo * head){
//	if (head != NULL){
//		printf("\n%i",pAux->data);
//		printAllRecursive(head->prox);
//	}
//}

void destroy(TNo ** head){
    TNo * pAnt = *head;
    TNo * pProx = *head;
    while (pProx != NULL){
        pProx = pProx->prox;
        free(pAnt);
        pAnt = pProx;
    }
    *head = NULL;
}

void destroyRecursive(TNo ** head){
    TNo * pAux = *head;
    if (pAux != NULL){
        destroyRecursive(&(pAux->prox));
        free(pAux);
        *head = NULL;
    }
}