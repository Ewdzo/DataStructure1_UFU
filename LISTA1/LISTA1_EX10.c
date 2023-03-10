#include <stdio.h>

void main(){
    int code[5], vehicles[5], accidents[5], moreAccidents, lessAccidents, moreCity = 0, lessCity = 0, smallCities = 0;
    float averageVehicles = 0, averageAccidents = 0;

    for(int i = 0; i < 5; i++){
        printf("\nCode of City: ");
        scanf("%d", &code[i]);

        printf("Number of Vehicles: ");
        scanf("%d", &vehicles[i] );

        printf("Number of Accidents: ");
        scanf("%d", &accidents[i]);

        if(i == 0){
            moreAccidents = accidents[i];
            lessAccidents = accidents[i];
        }
        else {
            if( moreAccidents <= accidents[i] ) {
                moreAccidents = accidents[i]; 
                moreCity = code[i];
            }
            if( lessAccidents >= accidents[i] ) {
                lessAccidents = accidents[i]; 
                lessCity = code[i];
            }
        }

        if(vehicles[i] < 2000){
            smallCities++; 
            averageAccidents += accidents[i];
        }

        averageVehicles += (vehicles[i]/5);
    }

    printf("\nMost Accidents: %d in city code %d.\nLess Accidents; %d in city code %d.", moreAccidents, moreCity, lessAccidents, lessCity);
    printf("\nAverage Vehicles: %f", averageVehicles);
    printf("\nAverage Accidents in Small Cities: %f", averageAccidents);

}