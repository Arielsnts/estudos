#include <stdio.h>

int primo(int num) {
    int cont = 0;

    if (num == 1) return 0;

    for (int  i = 1; i <= num; i++) {
        if (num % i == 0) cont++;
        if (cont > 2) return 0;
    }
    return 1;
}

int main() {
    int n = 0;

    scanf("%d", &n);

    int matriz[n][n];

    int cont = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (primo(matriz[i][j])) cont++;
        }
    }
    
    int arrPrimo[cont];

    int index = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (primo(matriz[i][j]) == 1) {
                arrPrimo[index] = matriz[i][j];
                index++;
            }
        }
    }

    for (int i = 0; i < cont - 1; i++) {
        for (int j = 0; j < cont - i - 1; j++) {
            if (arrPrimo[j] > arrPrimo[j + 1]) {
                int temp = arrPrimo[j];
                arrPrimo[j] = arrPrimo[j + 1];
                arrPrimo[j + 1] = temp;
            }
        }
    }
    

    for (int i = 0; i < cont; i++) {
        printf("%d ", arrPrimo[i]);
    }

    return 0;
}