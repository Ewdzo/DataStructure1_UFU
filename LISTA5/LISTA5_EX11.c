#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isVowel(char letter){
    letter = toupper(letter);

    if(letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U') return 1;
    else return 0;
}

int checkVowels(char *firstWord, char *secondWord){
    int vowels = 0;

    for(int i = 0; i < strlen(firstWord); i++){
        vowels = vowels + isVowel(firstWord[i]);
    };

    for(int i = 0; i < strlen(secondWord); i++){
        vowels = vowels + isVowel(firstWord[i]);
    };

    return vowels;
}

int main(){
    char nameOne[50], nameTwo[50];

    printf("Insert the first name: ");
    gets(nameOne);
    setbuf(stdin, 0);

    printf("Insert the second name: ");
    gets(nameTwo);

    printf("\nBoth names have %d letters at total.", checkVowels(nameOne, nameTwo));

    return 0;
}