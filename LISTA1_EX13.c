#include <stdio.h>

void main(){
    int numbers[50];

    for(int i = 0; i<50; i++){
        scanf("%d", &numbers[i]);
    }

    for(int i = 0; i<50; i++){
        if(numbers[i] > 0){
            print("%d ", numbers[i]);
        }
    }
}