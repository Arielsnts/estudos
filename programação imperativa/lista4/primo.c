#include <stdio.h>

int main() {
    int entrada;

    while (1) {
        scanf("%d", &entrada);

        if (entrada == -1) break;

        int primo = 1;

        int i = 1, cont = 0;

        while (i <= entrada) {
            if (entrada % i == 0) cont++;
            i++;
        }

        if (cont != 2) primo = 0;

        printf("%d\n", primo);
    }
    
    return 0;
}
