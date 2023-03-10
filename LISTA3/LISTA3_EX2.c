#include <stdio.h>

float calcAvg(float number1, float number2){
    if(number1 > number2) return number1;
    else return number2;

}

void main(){
    float aux1, aux2, biggest;

    printf("Pick a Number: ");
    scanf("%f", &aux1);

    printf("Pick a Second Number: ");
    scanf("%f", &aux2);

    biggest = calcAvg(aux1, aux2);
    printf("The Biggest Number: %f", biggest);
}
