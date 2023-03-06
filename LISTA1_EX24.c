#include <stdio.h>

void main(){
    int numbers[15][5], count = 0;

    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            printf("Pick a number for [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);
        }
    }

    for(int i=0; i<15; i++){
        for(int j=0; j<5; j++){
            count = 0;

            for(int k=0; k<15; k++){
                for(int l = 0; l<5; l++){
                    if(numbers[k][l] == numbers[i][j]) count++;
                }
            }

            if(count > 1) printf("\nThe number %d appears %d times.", numbers[i][j], count);
        }
    }
}