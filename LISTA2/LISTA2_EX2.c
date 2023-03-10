#include <stdio.h>

int calcPrice(){
    float cost;

    printf("Insert the car original cost: $");
    scanf("%f", &cost);

    cost = cost + (cost * 0.45) + (cost * 0.28);

    printf("Final Cost: $%.2f", cost);

    return 0;
}

void main(){
    calcPrice();
}