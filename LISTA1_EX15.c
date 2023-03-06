#include <stdio.h>

void main(){
    int numbers[6], negatives = 0, positives = 0, negativeSum = 0; positiveSum = 0;

    for(int i = 0; i<50; i++){
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i<50; i++){
        if(numbers[i] > 0){
            negatives++;
            negativeSum += numbers[i];
        }
        else {
            positiveSum+= numbers[i];
            positives++;
        }
    }

    printf("Negatives: %d\nNegative Sum: %d\nPositives: %d\nPositives Sum: %d", negatives, negativeSum, positives, positiveSum);
}