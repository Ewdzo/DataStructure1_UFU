#include <stdio.h>

void main(){
    int N, number, aux;

    printf("Choose number N: ");
    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        printf("\nPick a number: ");
        scanf("%d", &number);
        aux = number;

        for(int j = 1; j < aux; j++) number = number * j;

        printf("Factorial: %d", number);
    };
}
