#include <stdio.h>
#include <string.h>
#define N 10

typedef struct{
    char licensePlate[8];
} car;

typedef struct{
    int top;
    car cars[N];
} stack;

void push(car x, stack *stack){
    if ((*stack).top == (N-1)) printf("%s", "stack overflow");
    else (*stack).cars[(++(*stack).top)] = x;
}

car pop(stack *stack){
    if ((*stack).top == -1){
        printf("%s", "stack underflow");

        car aux;
        return(aux);
    }
    else return((*stack).cars[(*stack).top--]);
};

void main(){
    stack parked, waiting;
    char input[10];

    while(1){
        setbuf(0, stdin);
        printf("\nInsert Char and Plate (Ex: C AAA-0000): ");
        fgets(input, 11, stdin);

        if(input[0] == 'C') {
            car aux;

            for(int i = 0; i<9; i++) { aux.licensePlate[i] = input[i+2]; }

            if(parked.top != (N-1)) {
                push(aux, &parked);
                printf("\n%s - Parked ", aux.licensePlate);
            }
            else {
                printf("\n%s - Waiting ", aux.licensePlate);
                push(aux, &waiting);
            };
        }
        // else if(input[0] == 'P'){
        //     car aux;
        //     int position = -1;

        //     for(int i = 0; i<9; i++) { aux.licensePlate[i] = input[i+2]; }

        //     for(int i = 0; i <= parked.top; i++) {
        //         if(aux.licensePlate == parked.cars[i].licensePlate) position = i;
        //     };

        //     if(position != -1){
        //         for(int i = parked.top; i>position; i--) {
        //             printf("\n%s - Waiting ", parked.cars[i].licensePlate);
        //             push(pop(&parked), &waiting);
        //         }
        //         pop(&parked);

        //         for(int i = parked.top; i != (parked.top- 1); i++) {
        //             printf("\n%s - Parked ", waiting.cars[i].licensePlate);
        //             push(pop(&waiting), &parked);
        //         }
        //     }
        //     else printf("\n%s - Not Found", aux.licensePlate);
        // }
    }


    

}