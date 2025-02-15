#include <stdio.h>

int main() {
    int casa = 0;

    int contCasa = 0;
    float soma = 0;

    while (1) {
        scanf("%d", &casa);

        if (casa == 999) break;

        if (casa > 2) {
            contCasa++;
            soma = soma + ((casa - 2) * 12.89);
        }
    }

    printf("%.2f\n%d\n", soma, contCasa);

    return 0;
}