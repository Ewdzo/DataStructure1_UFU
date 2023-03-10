#include <stdio.h>

void main(){
    int numbers[6][4], altered[6][4], count = 0;

    for(int i=0; i<6; i++){
        for(int j=0; j<4; j++){
            printf("Pick a number for [%d][%d]: ", i, j);
            scanf("%d", &numbers[i][j]);

            altered[i][j] = numbers[i][j];
            
            if(numbers[i][j] > 30) count++;
            else if (numbers[i][j] == 30) altered[i][j] = 0;
        }
    }

    printf("There are %d numbers bigger than 30.", count);
}