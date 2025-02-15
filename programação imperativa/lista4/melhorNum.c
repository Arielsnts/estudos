#include <stdio.h>

int main() {
    int entrada, num, soma=0;

    scanf("%d", &entrada);

    int valor = entrada;

    while (entrada > 0) {
        num = entrada % 10;

        int fatorial = 1;

        for (int i = 1; i <= num; i++) {
            fatorial *= i;
        }

        soma += fatorial;

        entrada /= 10;
    }

    if (soma == valor) printf("melhor numero\n");
    else printf("nao\n");

    return 0;
}