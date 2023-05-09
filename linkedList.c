#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} listNode;

listNode *start = NULL;

void showList(){  
    if(start == NULL) printf("\nList is Empty.");
    else {
        
        listNode *aux = start;
        printf("\nElement List: ");
        while(aux){
            printf("\n%d", aux->data);
            aux = aux->next;
        }
    }
}

void addNode(listNode *newNode, int value){
    
    listNode *aux;
    newNode->data= value;
    newNode->next= NULL;

    if(start == NULL) start = newNode;
    else {
        aux = start;

        while(aux->next!=NULL){ aux= aux->next; }
        aux->next = newNode;
    }
}

void removeAll(){
    listNode *aux, *aux2;

    if(start == NULL) printf("\nLista Vazia.");
    else {
        aux = start;
        aux2 = aux;
        
        while(aux->next!=NULL){
            aux2 = aux;
            aux = aux->next;
            printf("\nRemoved Value: %d", aux2->data);
            free(aux2);
        }
    }    
}

void main(){
    int option = -1, value;

    while(option!=3){
        printf("\n1 - Add List Node\n2 - Show NodeList\n3 - Delete All\nOption: ");
        scanf("%d", &option);

        if(option==1){
            listNode *aux;

            printf("\nValue: ");
            scanf("%d", &value);

            if(value!=0){
                aux = (listNode *)malloc(sizeof(listNode));
                if(!aux) printf("\nNo Memory.");
                else addNode(aux, value);
            }
        }
        else if(option==2){
            listNode *aux = start, *p = start, *end;

            while(p->next!=NULL){ 
                end = p->next;
                p = p->next; 
            }
            printf("\nList of Elements Inverted: %d", end->data);

            while( p != start ){
                while( aux->next!=end ){ 
                    p = aux;
                    aux = aux->next; 
                };

                printf(" %d", aux->data);
                end = aux;
                aux = p;
                p = start;
                while( p->next!=aux ){ p = p->next; };
            }
            printf(" %d %d", aux->data, p->data);
        }
        else if(option==3){
            listNode *aux;
            while(start!=NULL){
                aux = start;
                printf("\nRemoved Value: %d", aux->data);
                start = aux->next;
                free(aux);
            }
            printf("\n === List Cleaned ===");
        }
    }
}