#include <stdio.h>

int main() {
    int vAvela, vCaramelo, vPassas; 
    int qAvela, qCaramelo, qPassas; 

    scanf("%d %d %d", &vAvela, &vCaramelo, &vPassas);
    scanf("%d %d %d", &qAvela, &qCaramelo, &qPassas);

    float total = (vAvela * qAvela) + (vCaramelo * qCaramelo) + (vPassas * qPassas);

    printf("Valor: R$%.2f\n", total);

    return 0;
}