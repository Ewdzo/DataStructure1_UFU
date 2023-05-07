#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} listNode;

void showList(listNode *start){
    listNode *aux = start;
    
    while(aux){
        printf("\n%d", aux->data);
        aux = aux->next;
    }
}

void addNode(listNode **start, listNode *newNode, int value){
    newNode->data = value;

    if(*start == NULL) newNode->next = NULL;
    else newNode->next=*start;
}

void main(){
    listNode n1, n2, n3;
    listNode *start;

    n1.data = 1;
    n2.data = 2;
    n3.data = 3;

    start = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = NULL;

    listNode n0;
}