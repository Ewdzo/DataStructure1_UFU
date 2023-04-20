#include <stdio.h>
#include <string.h>
#define N 10

typedef struct{
    int top;
    char licensePlate[N][8];
} stack;

void push(char *x, stack *stack){
    if ((*stack).top == (N-1)) printf("%s", "stack overflow");
    else *(*stack).licensePlate[(++(*stack).top)] = *x;
}

char *pop(stack *stack){
    if ((*stack).top == -1){
        printf("%s", "stack underflow");
        return '0';
    }
    else return((*stack).licensePlate[(*stack).top--]);
};

void main(){
    stack parked, waiting;
    char input[10];
    char aux[8];

    while(1){
        printf("\nInsert Char and Plate (Ex: C AAA-0000): ");
        gets(input);
        setbuf(NULL, stdin);

        if(input[0] == 'C') {
            for(int i = 0; i<9; i++) { aux[i] = input[i+2]; }

            if(parked.top != (N-1)) {
                push(aux, &parked);
                printf("\n%s - Parked ", aux);
            }
            else {
                printf("\n%s - Waiting ", aux);
                push(aux, &waiting);
            };
        }
        else if(input[0] == 'P') {
            printf("hi"); 
            int position = -1;

            for(int i = 0; i<9; i++) {
                aux[i] = input[i+2]; 
            }

            for(int i = 0; i <= parked.top; i++) { 
                if(aux == parked.licensePlate[i]) position = i; 
            };

            if(position != -1){
                for(int i = parked.top; i>=position; i--) {
                    printf("\n%s - Waiting ", parked.licensePlate[i]);
                    push(pop(&parked), &waiting);
                }
                pop(&parked);

                for(int i = parked.top; i != (parked.top- 1); i++) {
                    printf("\n%s - Parked ", waiting.licensePlate[i]);
                    push(pop(&waiting), &parked);
                }
            }
            else printf("\n%s - Not Found", aux);
        }
    }
}