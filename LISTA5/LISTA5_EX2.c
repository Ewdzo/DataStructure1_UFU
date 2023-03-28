#include <stdio.h>

int changeNumbers(int *n1, int *n2){
    int aux;
    
    aux = *n1;
    *n1 = *n2;
    *n2 = aux;

    return 0;
}

void main(){
    int number1 = 10, number2 = 20;

    changeNumbers(&number1, &number2);

    printf("%d %d", number1, number2);
}