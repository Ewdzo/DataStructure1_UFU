#include <stdio.h>

void main(){
    int age = 0, married= 0, single = 0, total = 0, split = 0, widow = 0;
    float ageWidower = 0;
    char state;

    while(age >= 0){
        fflush(stdin);
        
        printf("\nEstado Civil (C - Casado, S - Solteiro, V - Viuvo, D - Desquitado): ");
        scanf("%c", &state);
        fflush(stdin);

        printf("\nIdade: ");
        scanf("%d", &age);
        fflush(stdin);


        if(state == 'C') married++;
        else if(state == 'S') single++;
        else if(state == 'S') split++;
        else if(state == 'W') {
            ageWidower += age;
            widow++;
        };
    
        total++;
    }
 
    ageWidower = ageWidower / widow;

    printf("Casados: %d\nSolteiros: %d\nIdade Media dos Viuvos:%.2f\nDesquitados: %f%%", married, single, ageWidower, (split/total));
}               