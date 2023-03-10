#include <stdio.h>

void main(){
    int codigo;
    float limpeza = 0, alimentacao = 0, higiene = 0, valor = 1;

    while(valor != 0){
        printf("Valor Gasto: R$");
        scanf("%f", &valor);

        printf("Em que departamento?\n1 - Limpeza\n2 - Alimentacao\n3- Higiene\nDpt: ");
        scanf("%d", &codigo);

        if(codigo == 1) limpeza += valor;
        else if(codigo == 2) alimentacao += valor;
        else if(codigo == 3) higiene += valor;

    }

    printf("\nLimpeza: R$%.2f\nAlimentacao: R$%.2f\nHigiene: R$%.2f\nTotal: R$%.2f", limpeza, alimentacao, higiene, (limpeza + alimentacao + higiene));
}