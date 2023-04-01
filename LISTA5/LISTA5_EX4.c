#include <stdio.h>
#include <string.h>
# define N 5
# define M 50

int checkLetters(int matrixLines, char matrix[][M], int array[], int *arrayLength){
    for(int i=0; i<matrixLines; i++){
        int strLength = strlen(matrix[i]);

        if(matrix[i][0] == matrix[i][strLength-1]){
            array[*arrayLength] = i;
            *arrayLength++;
        }
    }
}

int main(){
    int wordsQty, length = 0;

    printf("Words Quantity: ");
    scanf("%d", &wordsQty);

    char words[wordsQty][M];
    int sameLettersArray[wordsQty];

    for(int i=0; i < wordsQty; i++){
        printf("Word in [%d]: ", i);
        setbuf(stdin, 0);
        fgets(words[i], M, stdin);
    }

    checkLetters(wordsQty, words, sameLettersArray, &length);
    printf("%d", length);

    for(int i=0; i < 5; i++){ printf("\n[%d]", sameLettersArray[i]); }

    return 0;
};
