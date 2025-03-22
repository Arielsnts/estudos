#include <stdio.h>
#include <string.h>

int main() {
    int entrada = 0, expoente = 1;

    scanf("%d%*c%d", &entrada, &expoente);

    for (int i = 0; i < expoente; i++) {
        entrada * entrada;
    }

    printf("%d\n", entrada);

    return 0; 
}