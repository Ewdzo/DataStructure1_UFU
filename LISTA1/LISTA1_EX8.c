#include <stdio.h>

void main(){
    int product, country;
    float weight, price;

    printf("Code of Product: ");
    scanf("%d", &product);

    printf("Code of Origin Country: ");
    scanf("%d", &country);

    printf("Weight of Product(kg): ");
    scanf("%f", &weight);

    weight = weight * 1000;
    printf("\nWeight in grams: %f\n", weight);

    if(product >= 1 && product <= 4) price = weight * 10;
    else if(product >= 5 && product <= 7) price = weight * 25;
    else if(product >= 8 && product <= 10)price = weight * 35;

    if(country == 1) printf("Tax: 0\nFinal Price: %f", price);
    else if(country == 2) printf("Tax: %f\nFinal Price: %f", (price*0.15), (price * 1.15));
    else if(country == 3) printf("Tax: %f\nFinal Price: %f", (price*0.25), (price * 1.25));
}
