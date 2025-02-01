#include <stdio.h>

int main() {
    char tipo;
    int dias, tv, internet;

    scanf("%c%*s %d %d %d", tipo, dias, tv, internet);

    if (tipo == 'S') printf("%.2f\n", (dias * 150.0) + (tv * 10.0) + (internet * 15.0));
    else if (tipo == 'P') printf("%.2f\n", (dias * 200.0) + (tv * 10.0) + (internet * 15.0));

    return 0;
}