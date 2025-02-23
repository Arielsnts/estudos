#include <stdio.h>

int main() {
    char entrada[301];

    fgets(entrada, 301, stdin);

    char saida[301];

    int i = 0, j = 0, espaco = 0;
    while (entrada[i] != '\0') {
        if (entrada[i] != ' ') {
            saida[j] = entrada[i];
            espaco = 0;
            j++;
        }
        else if (espaco == 0) {
            saida[j] = ' ';
            espaco = 1;
            j++;
        }
        i++;
    }

    saida[j] = '\0';

    printf("%s", saida);
}
