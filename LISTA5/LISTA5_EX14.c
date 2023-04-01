#include <stdio.h>
#include <string.h>

char duplicateWord(char *phrase){
    char *word = strtok(phrase, " ");

    while( word != NULL){
        for(int i = 0; i<2; i++){ printf("%s ", word);};
        word = strtok(NULL, " ");
    }
}

void main(){
    char input[100];

    printf("Insert a Phrase: ");
    setbuf(stdin, 0);
    gets(input);
    
    duplicateWord(input);    
}