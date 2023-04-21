#include <stdio.h>
#include <string.h>

typedef struct{
    int top;
    char licensePlate[10][9];
} stack;

void push(char *x, stack *stack){
    if ((*stack).top == (9)) printf("%s", "stack overflow");
    else {
        (++(*stack).top);

        for(int i = 0; i<9; i++) {
            (*stack).licensePlate[((*stack).top)][i] = x[i];
        }
    }
}

char *pop(stack *stack){
    if ((*stack).top == -1){
        printf("%s", "stack underflow");
        return NULL;
    }
    else return((*stack).licensePlate[(*stack).top--]);
};

void main(){
    stack parked, waiting;
    parked.top = -1;
    waiting.top = -1;

    char input[10];
    char aux[9];

    while(1){
        printf("\nInsert Char and Plate (Ex: C AAA-0000): ");
        gets(input);
        setbuf(NULL, stdin);

        for(int i = 0; i<9; i++) { aux[i] = input[i+2]; };
        
        if(input[0] == 'C') {

         if(parked.top != 9) {   
                push(aux, &parked);
                printf("\n%s - Parked ", aux);
            }
            else {
                printf("\n%s - Waiting ", aux);
                push(aux, &waiting);
            };
        }
        else if(input[0] == 'P') {
            int position = -1;

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