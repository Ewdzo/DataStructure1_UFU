#include <stdio.h>

int calcSum(){
    float sum = 0, numbers[8];

    for(int i=0; i<8; i++){
        printf("Insert the %dth number: ", &sum);
        scanf("%f", &numbers[i]);
        sum += numbers[i];
    }

    printf("Final Sum: %f", sum);

    return 0;
}

void main(){
    calcSum();
}