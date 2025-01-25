#include <stdio.h>
#include <math.h>

int main() {
    float peso, altura;

    scanf("%f %f", &peso, &altura);

    float imc = peso / pow(altura, 2);

    printf("%.2f\n", imc);

    return 0;
}