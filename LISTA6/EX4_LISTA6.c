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

    while(option != 5){
        printf("\n\n1 - Insert Elements into Stack\n2 - Remove Elements from Stack\n3 - Check Stack Top\n4 - Show Stack\n5 - Exit\n\nOption: ");
        scanf("%d", &option);

        if(option == 1){
            printf("Pick a Number to be Inserted: ");
            scanf("%d", &aux);
            push(aux, &stack1);
        }
        else if(option == 2){
            printf("Removed %d.", pop(&stack1));
        }
        else if(option == 3){
            printf("Current Top: %d", stack1.data[stack1.top]);
        }
        else if(option == 4){
            printf("Stack: ");
            for(int i = 0; i <= stack1.top; i++) printf(" %d", stack1.data[i]);
        }
    }

};
