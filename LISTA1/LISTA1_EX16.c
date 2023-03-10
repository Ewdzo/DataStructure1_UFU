#include <stdio.h>

void main(){
    int numbersA[10], numbersB[10], sum[10];

    for(int i = 0; i<10; i++){
        printf("%dº number in first array: ", (i+1));
        scanf("%d", &numbersA[i]);
        printf("%dº number in second array: ", (i+1));
        scanf("%d", &numbersB[i]);

        sum[i] = numbersA[i] + numbersB[i];
    }

    printf("Sum Array: ");
    for(int i = 0; i<10; i++){
        printf("%d ", sum[i]);
    }
}