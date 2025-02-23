#include <stdio.h>
#include <string.h>

int main() {
    int nPares = 0;
    
    scanf("%d", &nPares);

    char arrayCadeia[nPares * 2][10];
    
    for (int i = 0; i < nPares*2; i++) {
        scanf("%s", arrayCadeia[i]);
    }

    int cadeia = 0;

    while (cadeia < (nPares * 2) - 1) {
        int cont = 0;

        for (int i = 0, j = 0; i < strlen(arrayCadeia[cadeia]); i++) {
            if (arrayCadeia[cadeia][i] == 'A' && arrayCadeia[cadeia + 1][i] == 'T') cont++;
            else if (arrayCadeia[cadeia][i] == 'T' && arrayCadeia[cadeia + 1][i] == 'A') cont++;
            else if (arrayCadeia[cadeia][i] == 'G' && arrayCadeia[cadeia + 1][i] == 'C') cont++;
            else if (arrayCadeia[cadeia][i] == 'C' && arrayCadeia[cadeia + 1][i] == 'G') cont++;
        }

        if (cont == strlen(arrayCadeia[cadeia])) printf("COMPLEMENTARES\n");
        else if (cont != strlen(arrayCadeia[cadeia])) {
            printf("NAO COMPLEMENTARES\n");
            for (int i = 0; i < strlen(arrayCadeia[cadeia]); i++) {
                if (arrayCadeia[cadeia][i] == 'A') arrayCadeia[cadeia+1][i] = 'T';
                else if (arrayCadeia[cadeia][i] == 'T') arrayCadeia[cadeia+1][i] = 'A';
                else if (arrayCadeia[cadeia][i] == 'C') arrayCadeia[cadeia+1][i] = 'G';
                else if (arrayCadeia[cadeia][i] == 'G') arrayCadeia[cadeia+1][i] = 'C';
            }
            printf("%s\n", arrayCadeia[cadeia+1]);
        }
        
        cadeia += 2;
    }

    return 0;
}