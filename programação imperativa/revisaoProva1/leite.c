#include <stdio.h>

int main() {
    float leiteA, leiteB, leiteC;

    scanf("%f %f %f", &leiteA, &leiteB, &leiteC);

    float totalLeite = leiteA + leiteB + leiteC;

    int tipoFinal = 0;

    if (leiteB == 0 && leiteC == 0) tipoFinal = 1;
    else if (leiteA == 0 && leiteC == 0) tipoFinal = 2;
    else if (leiteA == 0 && leiteB == 0) tipoFinal = 3;

    else if (leiteC == 0) {
        if (leiteA >= (0.9 * totalLeite)) tipoFinal = 1;
        else if (leiteA > (0.5 * totalLeite) && leiteA < 0.9 * totalLeite) tipoFinal = 2;
        else if (leiteB >= (0.5 * totalLeite)) tipoFinal = 3;
    }
    else if (leiteA == 0) {
        if (leiteB >= (0.75 * totalLeite)) tipoFinal = 2;
        else tipoFinal = 3;
    }
    else if (leiteB == 0) {
        if (leiteA >= (0.95 * totalLeite)) tipoFinal = 1;
        else tipoFinal = 3;
    }

    float valorTotal;

    if (tipoFinal == 1) valorTotal = totalLeite * 4.8;
    if (tipoFinal == 2) valorTotal = totalLeite * 3.6;
    if (tipoFinal == 3) valorTotal = totalLeite * 2.75;

    printf("%.2f\n", valorTotal);

    return 0;
}