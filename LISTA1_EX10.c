#include <stdio.h>

void main(){
    int code[5], vehicles[5], accidents[5], moreAccidents, lessAccidents;
    float averageVehicles, averageAccidents;

    for(int i = 0; i < 5; i++){
        printf("Code of City: ");
        scanf("%d", &code[i]);

        printf("Number of Vehicles: ");
        scanf("%d", &vehicles[i] );

        printf("Number of Accidents: ");
        scanf("%d", &accidents[i]);

        if(i == 0){
            moreAccidents = accidents;
            lessAccidents = accidents;
        }
    }

}