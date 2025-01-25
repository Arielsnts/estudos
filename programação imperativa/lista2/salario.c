#include <stdio.h>

int main() {
    float salario;

    scanf("%f", &salario);

    float porcentagem;

    if (salario >= 500) porcentagem = 10;
    else if (salario >= 300 && salario < 500) porcentagem = 7;
    else porcentagem = 5;

    float aumento = salario + ((porcentagem / 100) * salario);

    printf("%.2f\n", aumento);

    return 0;
}