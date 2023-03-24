#include <stdio.h>

int sortNumbers(int *n1, int *n2, int *n3){
    int aux;

    if(*n1 < *n2 && *n1 < *n3) {
        aux = *n3;
        *n3 = *n1;
        
        if(*n2 > aux) {
            *n1 = *n2;
            *n2 = aux;
        }
        else *n1 = aux;
    }
    else if(*n2 > *n1){
        aux = *n1;
        *n1 = *n2;
        *n2 = aux;
    }
    else if(*n2 < *n1 && *n2 < *n3){
        aux = *n2;
        *n2 = *n3;
        *n3 = aux;

        if(*n2 > *n1) {
            aux = *n1;
            *n1 = *n2;
            *n2 = aux;
        }
    };
 
}

void main(){
    int number1 = 20, number2 = 10, number3 = 30;

    printf("\n%d %d %d", number1, number2, number3);
    sortNumbers(&number1, &number2, &number3);

    printf("\n%d %d %d", number1, number2, number3);
}