#include <stdio.h>

int checkPassword(int password){
    if(password == 4531) return 1;
    else return 0;
}

void main(){
    int pwInput;

    printf("Insert the password: ");
    scanf("%d", &pwInput);

    if(checkPassword(pwInput)) printf("You're logged in.");
    else printf("Incorrect password.");
}
