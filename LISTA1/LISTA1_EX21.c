#include <stdio.h>

void main(){
    int numbers[100], option = 0, qty = 0, delete;

    while(option != 4){
        printf("\n\n1 - Register\n2 - Delete\n3 - Show\n4 - Quit\nOption: ");
        scanf("%d", &option);

        if(option == 1){
            printf("%dth Number: ", (qty+1));
            scanf("%d", &numbers[qty]);
            qty++;
        }
        else if(option == 2){
            printf("Delete Number: ");
            scanf("%d", &delete);

            for(int i = 0; i<qty; i++){
                if(numbers[i] == delete){
                    for(int j = i; j<qty; j++){
                        numbers[j] = numbers[j+1];
                        qty--;
                    }
                }
            } 
        }
        else if(option == 3){
            printf("Numbers: ");
            for(int i = 0; i<qty; i++){
                printf("%d ", numbers[i]);
            } 
        }
    }
}