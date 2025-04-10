#include <stdio.h>
#include <stdlib.h>

void quadrado(int *x) {
    *x *= *x;
}

int main() {
    int x = 2;

    printf("%d\n", x);

    quadrado(&x);

    printf("%d\n", x);

    return 0; 
}