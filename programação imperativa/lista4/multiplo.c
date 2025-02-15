#include <stdio.h>

int main() {
    int entrada;

    scanf("%d", &entrada);

    if (entrada <= 0) return 0;

    for (int i = 1; i <= 10; i++) {
        printf("%d\n", entrada * i);
    }

    return 0;
}
