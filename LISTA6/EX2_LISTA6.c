#include <stdio.h>
#define N 6

typedef struct{
    int top;
    int data[N];
} stack;

void push(int x, stack *stack){
    if ((*stack).top == (N-1)) printf("%s", "stack overflow");
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
    stack stack1;
    int x;
    stack1.top = -1;

    for(int i=0; i<(N-1); i++){
        int aux;
        printf("Insert stack1.data[%d]: ", i);
        scanf("%d", &aux);
        push(aux, &stack1);
    }

    printf("Insert X: ");
    scanf("%d", &x);

    if(x < 100) {
        push(x, &stack1);
        printf("X added!");
    }
    else printf("Pop'ed: %d", pop(&stack1));


};
