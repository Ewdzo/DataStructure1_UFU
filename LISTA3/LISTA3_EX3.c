#include <stdio.h>

float investCapital(int type, float capital){
    if(type == 1) return (capital * 1.03);
    else if(type == 2) return (capital * 1.04);
}

void main(){
    float money;
    int investmentType;

    printf("Pick a Type of Investment (1 - Savings || 2 - Fixed Income Fund): ");
    scanf("%d", &investmentType);

    printf("How much to apply: R$");
    scanf("%f", &money);

    money = investCapital(investmentType, money);
    printf("Money Returned: R$%.2f", money);
}
