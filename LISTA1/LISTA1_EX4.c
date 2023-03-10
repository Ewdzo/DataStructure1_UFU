#include <stdio.h>

void main(){
    float price, budget;

    printf("Insert the price per liter of gas: R$");
    scanf("%f", &price);

    printf("Insert much you want to pay: R$");
    scanf("%f", &budget);

    printf("You will fill your car with %f liters of gas.", (budget/price));
}