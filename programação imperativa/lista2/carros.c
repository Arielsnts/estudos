#include <stdio.h>

int main() {
    int dias, km;

    scanf("%d %d", &dias, &km);

    float diaria = dias * 90;

    int cotaKm = dias * 100;

    float valorExtra = 0.0;

    if (km > cotaKm) {
        valorExtra = (km - cotaKm) * 12;
    }

    float total = valorExtra + diaria;
    printf("%.2f\n", total);
    return 0;
}