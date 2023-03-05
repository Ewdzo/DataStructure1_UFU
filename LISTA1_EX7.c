#include <stdio.h>

void main(){
    int I;
    float A, B, C;

    printf("Value of A: ");
    scanf("%f", &A);

    printf("Value of B: ");
    scanf("%f", &B);

    printf("Value of C: ");
    scanf("%f", &C);

    printf("\n1 - Crescent\n2 - Decrescent\n3 - Biggest in the middle\nOption: ");
    scanf("%d", &I);

    if(I == 1){
        if(A >= B && A >= C){
            if(B >= C){
                    printf("%f, %f and %f", C, B, A);
               }
            else{
                printf("%f, %f and %f", B, C, A);
            }
        }
        else if( B >= A &&  B >= C){
            if(A >= C){
                    printf("%f, %f and %f", C, A, B);
               }
            else{
                printf("%f, %f and %f", A, C, B);
            }
        }
        else if( C >= A &&  C >= B){
            if(B >= A){
                    printf("%f, %f and %f", A, B, C);
               }
            else{
                printf("%f, %f and %f", B, A, C);
            }
        }
    }
    else if(I == 2){
        if(A >= B && A >= C){
            if(B >= C){
                    printf("%f, %f and %f", A, B, C);
               }
            else{
                printf("%f, %f and %f", A, C, B);
            }
        }
        else if( B >= A &&  B >= C){
            if(A >= C){
                    printf("%f, %f and %f", B, A, C);
               }
            else{
                printf("%f, %f and %f", B, C, A);
            }
        }
        else if( C >= A &&  C >= B){
            if(B >= A){
                    printf("%f, %f and %f", C, B, A);
               }
            else{
                printf("%f, %f and %f", C, A, B);
            }
        }
    }
    else if(I == 3){
        if(A >= B && A >= C){
           printf("%f, %f and %f", B, A, C);
        }
        else if( B >= A &&  B >= C){
           printf("%f, %f and %f", A, B, C);
        }
        else if( C >= A &&  C >= B){
           printf("%f, %f and %f", A, C, B);
        }
    }

}
