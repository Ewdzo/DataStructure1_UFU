#include <stdio.h>

void main(){
    int numbers[10][20], sum[10], aux;

    for(int i=0; i<10; i++){
        aux = 0;

        for(int j=0; j<20; j++){
            printf("Pick a number for [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
            aux += numbers[i][j];
        }

        sum[i] = aux;
    }

    for(int i=0; i<10; i++){
        for(int j=0; j<20; j++){
            numbers[i][j] = numbers[i][j] * sum[i];
            printf("%d ", sum[i]);
        }
        
        printf("\n");
    }

}