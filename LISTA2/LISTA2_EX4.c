#include <stdio.h>

int calcEvenSum(){
    int sum = 0, numbers[2][3];

    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            printf("Insert the [%d][%d]: ", &i, &j);
            scanf("%f", &numbers[i]);
            if(numbers[i][j] % 2 == 0) sum += numbers[i][j];
        }
    }

    printf("Final Sum of Evens: %f", sum);

    return 0;
}

void main(){
    calcEvenSum();
}