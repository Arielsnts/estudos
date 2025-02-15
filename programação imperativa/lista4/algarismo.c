#include <stdio.h>

int main() {
    int entrada, num, soma=0;

    scanf("%d", &entrada);

    while (entrada > 0) {
        num = entrada % 10;
        soma += num;
        entrada /= 10;
    }

    printf("%d\n", soma);
    
    return 0;
}