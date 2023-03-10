#include <stdio.h>

void main(){
    int numbers[8], negatives = 0, positives = 0, negativeArray[8], positiveArray[8];

    for(int i = 0; i<8; i++){
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i<8; i++){
        if(numbers[i] < 0){
            negativeArray[negatives] = numbers[i];
            negatives++;
        }
        else {
            positiveArray[positives] = numbers[i];
            positives++;
        }
    }

    printf("\nPositives: ");
    for(int i = 0; i<positives; i++){
        printf("%d ", positiveArray[i]);
    }

    printf("\nNegatives: ");
    for(int i = 0; i<negatives; i++){
        printf("%d ", negativeArray[i]);
    }
}