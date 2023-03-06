#include <stdio.h>

void main(){
    int numbers[10], negatives = 0, positiveSum = 0;

    for(int i = 0; i<50; i++){
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i<50; i++){
        if(numbers[i] > 0){
            negatives++;
        }
        else {
            positiveSum += numbers[i];
        }
    }

    printf("Negatives: %d\nPositive Sum: %d", negatives, positiveSum);
}