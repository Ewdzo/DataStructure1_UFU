#include <stdio.h>

void main(){
    float grade = 0.0, aux;

    printf("Lab Assignment: ");
    scanf("%f", &aux);
    grade += (0.2 * aux);

    printf("Semestral Exam: ");
    scanf("%f", &aux);
    grade += (0.3 * aux);

    printf("Final Exam: ");
    scanf("%f", &aux);
    grade += (0.5 * aux);

    if(grade >= 8.01 && grade <= 10.0){
        printf("Concept A!");
    }
    else if(grade >= 7.01){
        printf("Concept B.");
    }
    else if(grade >= 6.01){
        printf("Concept C.");
    }
    else if(grade >= 5.01){
        printf("Concept D.");
    }
    else {
        printf("Concept E.");
    }
}
