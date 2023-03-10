#include <stdio.h>

float calcAvg(float labAssignment, float semestralExam, float finalExam){
    float avg = 0.0;

    avg += (0.2 * labAssignment);
    avg += (0.3 * semestralExam);
    avg += (0.5 * finalExam);

    return avg;
}

void main(){

    float lab, semestral, final;

    printf("Lab Assignment: ");
    scanf("%f", &lab);

    printf("Semestral Exam: ");
    scanf("%f", &semestral);

    printf("Final Exam: ");
    scanf("%f", &final);


    float grade = calcAvg(lab, semestral, final);
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