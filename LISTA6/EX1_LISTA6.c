#include <stdio.h>

typedef struct{
    int top;
    int data[20];
} stack;

void push(int x, stack *stack){
    if ((*stack).top == 19) printf("%s", "stack overflow");
    else (*stack).data[(++(*stack).top)] = x;
}

int pop(stack *stack){
    if ((*stack).top == -1){
        printf("%s", "stack underflow");
        return(-1);
    }
    else return((*stack).data[(*stack).top--]);
};

void main(){
    stack stack1, stack2, stack3;
    stack1.top = -1;
    stack2.top = -1;
    stack3.top = -1;

    for(int i=0; i<20; i++){
        int aux;
        printf("Insert stack1.data[%d]: ", i);
        scanf("%d", &aux);
        push(aux, &stack1);
    }

    for(int i=0; i<20; i++){
        int aux;
        aux = pop(&stack1);
        if(aux < 100) push(aux, &stack2);
        else push(aux, &stack3);
    }

    printf("\nStack2: ");
    for(int i=0; i <= stack2.top; i++){
        printf(" %d", stack2.data[i]);
    }

    printf("\nStack3: ");
    for(int i=0; i <= stack3.top; i++){
        printf(" %d", stack3.data[i]);
    }
};
