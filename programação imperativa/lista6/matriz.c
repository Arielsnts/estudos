#include <stdio.h>

int main() {
    int matriz[3][3];

    scanf("%d", &matriz[0][0]);
    int maior = matriz[0][0];
    int soma = matriz[0][0];

    for (int i = 0; i < 3; i++) {
        for (int j = (i == 0 ? 1 : 0); j < 3; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > maior) maior = matriz[i][j];
            soma += matriz[i][j];
        }
    }

    float media = (float) soma / 9.0;

    int diagonalPrincipal = matriz[0][0] + matriz[1][1] + matriz[2][2];
    
    int delta = 0;
    if (maior > 0) delta = 1;
    else if (maior < 0) delta = -1;

    printf("%.2f %d %d %d\n", media, maior, delta, diagonalPrincipal);

    return 0;
}