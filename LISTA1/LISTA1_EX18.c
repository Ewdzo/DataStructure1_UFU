#include <stdio.h>

void main(){
    int numbersA[10], numbersB[10], numbersC[20], qty = 0;

    for(int i = 0; i<10; i++){
        printf("Number for first array: ");
        scanf("%d", &numbersA[i]);
        printf("Number for second array: ");
        scanf("%d", &numbersB[i]);

        numbersC[qty] = numbersA[i];
        qty++;
        numbersC[qty] = numbersB[i];
        qty++;
    }
}