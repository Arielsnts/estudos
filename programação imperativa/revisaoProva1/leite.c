#include <stdio.h>

int main() {
    float leiteA, leiteB, leiteC;

    scanf("%f %f %f", &leiteA, &leiteB, &leiteC);

    float totalLeite = leiteA + leiteB + leiteC;
    
    float porcento50 = 0.5 * totalLeite;
    float porcento75 = 0.75 * totalLeite;
    float porcento90 = 0.9 * totalLeite;
    float porcento95 = 0.95 * totalLeite;

    int tipoFinal = 0;

    if (leiteC == 0) {
        if (leiteA >= porcento90) tipoFinal = 1;
        else if (leiteA > porcento50) tipoFinal = 2;
        else tipoFinal = 3;
    }
    else if (leiteA == 0) {
        if (leiteB >= porcento75) tipoFinal = 2;
        else tipoFinal = 3;
    }
    else if (leiteB == 0) {
        if (leiteA >= porcento95) tipoFinal = 1;
        else tipoFinal = 3;
    }
    else tipoFinal = 3;

    float valorTotal;

    if (tipoFinal == 1) valorTotal = totalLeite * 4.8;
    else if (tipoFinal == 2) valorTotal = totalLeite * 3.6;
    else if (tipoFinal == 3) valorTotal = totalLeite * 2.75;

    printf("%.2f\n", valorTotal);

    return 0;
}