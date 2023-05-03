#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
    int start, end;
    int licensePlate[MAX];
} queue;

void startQueue(queue *q){
    (*q).start = 0;
    (*q).end = 0;
}

void enqueue(queue *q, int value){
    if((*q).end != MAX) {
        (*q).licensePlate[(*q).end] = value;
        (*q).end++;
    }
    else printf("\nFull Queue\n");
}

void dequeue(queue *q, int *storage){
    if((*q).end != (*q).start){
        *storage = (*q).licensePlate[(*q).start];

        for(int i=0; i < (*q).end; i++){ (*q).licensePlate[i] = (*q).licensePlate[i+1]; }
        (*q).end--;
    }
    else printf("\nEmpty Queue\n");
}

void main(){
    queue parked, auxQueue, waiting; 
    int aux;
    char input;

    startQueue(&parked);
    startQueue(&waiting);

    while(1){
        printf("\nParked: ");
        for(int i = 0; i < parked.end; i++) { printf(" %d", parked.licensePlate[i]); };
        printf("\n\nInsert Char and Plate (Ex: C 1234567890): ");
        scanf("%c %d", &input, &aux);

        if(input == 'C'){
            if(parked.end != 9) {   
                enqueue(&parked, aux);
                printf("\n%d - Parked ", aux);
            }
            else {
                printf("\n%d - Waiting ", aux);
                enqueue(&waiting, aux);
            };
        }
        else if(input == 'P'){
            int position = -1;
            
            for(int i = 0; i < parked.end; i++) { if(aux == parked.licensePlate[i]) position = i; };

            if(position != -1){
                int endAux = parked.end;

                for(int i = 0; i < endAux; i++) {
                    dequeue(&parked, &aux);
                    
                    if(i != position) enqueue(&auxQueue, aux);
                    else printf("\n%d - Left", aux);
                }

                endAux = auxQueue.end;
                for(int i = 0; i < endAux; i++) {
                    dequeue(&auxQueue, &aux);
                    enqueue(&parked, aux);
                }

                for(int i = 0; ((parked.end != 9) && (waiting.end != 0)); i++){
                    dequeue(&waiting, &aux);
                    enqueue(&parked, aux);
                    printf("\n%d - Parked ", aux);
                }
            }
            else printf("\n%d - Not Found", aux);
        }
    }

}
