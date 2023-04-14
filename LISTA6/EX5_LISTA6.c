#include <stdio.h>
#include <string.h>

typedef struct{
    int top;
    char data[10];
} stack;

void push(int x, stack *stack){
    if ((*stack).top == 9) printf("%s", "stack overflow");
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
    int option = 0, aux;
    stack stack1;
    stack1.top = -1;

    
    printf("Insert Stack[%d]", &aux);
    scanf("%d", &aux);
};
