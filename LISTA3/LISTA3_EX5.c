#include <stdio.h>

int checkPrime(int number){ 
    int divisors = 0;

    for(int i = 1; i<number; i++){
        if(number % i == 0) divisors++;
    }
    
    if(number == 1) divisors++;

    if (divisors == 1) return 1;
    else return 0;
};

void main(){
    int input;

    printf("Pick a Number: ");
    scanf("%d", &input);

    if(checkPrime(input)) printf("It's a prime!");
    else printf("It isn't a prime!");
}
