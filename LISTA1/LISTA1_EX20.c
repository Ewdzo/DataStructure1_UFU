#include <stdio.h>

void main(){
    int number, available, numbers[10], i = 0;

    while(i < 10){
        printf("\n%dth Number: ", (i+1));
        scanf("%d", &number);
        available = 1;

        for(int j = 0; j < i; j++){
            if(number == numbers[j]) available = 0;
        }

        if(available == 1){
            numbers[i] = number;  
            printf("\nNumber registered.");
            i++;
        }
        else printf("\nThis number isn't available.");

    }
}