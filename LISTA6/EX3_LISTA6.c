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
    char input[100];
    stack stack1;
    stack1.top = -1;

    printf("Insert text: ");
    gets(input);

    for(int i=0; i < strlen(input); i++){
        if(input[i] == '(') push('(', &stack1);
        else if(input[i] == ')') pop(&stack1);
    }

    if(stack1.top == -1) printf("%s is a well-formed mathematic expression.", input);
    else printf("\n%s isn't a well-formed mathematic expression.", input);
};
