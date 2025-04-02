#include <stdio.h>

int main() {
    int n = 0;

    scanf("%d", &n);

    int matriz[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int soma = 0;

    for (int i = 0; i < n; i++) {
        soma += matriz[i][0];
    }
    
    int teste;
    
    for (int i = 1; i < n; i++) {
        teste = 0;
        for (int j = 0; j < n; j++) {
            teste += matriz[i][j];
        }
        if (teste != soma) {
            printf("-1\n");
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        teste = 0;
        for (int j = 0; j < n; j++) {
            teste += matriz[j][i];
        }
        if (teste != soma) {
            printf("-1\n");
            return 0;
        }
    }

    teste = 0;


    for (int i = 0; i < n; i++) {
        teste += matriz[i][i];
    }

    if (teste != soma) {
        printf("-1\n");
        return 0;
    }

    teste = 0;

    for (int i = 0, j = n - 1; i < n; i++, j--) {
        teste += matriz[i][j];
    }

    if (teste != soma) {
        printf("-1\n");
        return 0;
    }

    printf("%d\n", soma);
}