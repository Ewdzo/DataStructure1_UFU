#include <stdio.h>

void main(){
    int numbers[10], inverted[10];

    for(int i = 0; i<10; i++){
        printf("%dth Number: ", (i+1));
        scanf("%d", &numbers[i]);

        inverted[(10-i)] = numbers[i];
    }

}