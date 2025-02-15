#include <stdio.h>

int main() {
    int capacidade, encomendas;
    float custo;

    scanf("%d%*c%d%*c%f", &capacidade, &encomendas, &custo);

    float calculo = (encomendas - capacidade) * custo;

    printf("Custo de terceirizacao: R$%.2f\n", calculo);

    if (calculo > 100000.0) printf("ABRA UM NOVO CENTRO\n");
    else printf("NAO ABRA UM NOVO CENTRO\n");

    return 0;
}
