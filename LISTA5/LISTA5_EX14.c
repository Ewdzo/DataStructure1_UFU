#include <stdio.h>
#include <string.h>

char duplicateWord(char *phrase){
    char *word = strtok(phrase, " "), duplicatedPhrase[200] = {0};

    while(word != NULL){
        for(int i=0; i<2; i++){
            strcat(duplicatedPhrase, word);
            strcat(duplicatedPhrase, " ");
        };
        
        word = strtok(NULL, " ");
    }
+
    printf("%s", duplicatedPhrase);
};

void main(){
    char input[100];

    printf("Insert a Phrase: ");
    setbuf(stdin, 0);
    gets(input);
    
    duplicateWord(input);    
};