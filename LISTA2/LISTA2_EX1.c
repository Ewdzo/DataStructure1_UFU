#include <stdio.h>

int getAge(){
    int age = 0, aux, aux2, aux3;

    printf("Insert your age in years, months and days: ");
    scanf("%d %d %d", &aux, &aux2, &aux3);

    age += (aux * 365);
    age += (aux2 * 30);
    age += (aux3);

    printf("You're %d days old.", age);

    return 0;
}


void main(){
    getAge();
}