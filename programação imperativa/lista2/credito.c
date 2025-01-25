#include <stdio.h>

int main() {
    float salario, divida;

    scanf("%f %f", &salario, &divida);

    float porcentagem = 0.3 * salario;

    if (divida >= porcentagem) printf("0.00\n");
    else {
        float parcela = porcentagem - divida;

        printf("%.2f\n", parcela);
    }

    return 0;
}