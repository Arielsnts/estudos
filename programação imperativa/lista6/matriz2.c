#include <stdio.h>

int main() {
    int linha, coluna, menor_zero = 0, maior_zero = 0, principal = 0, secundaria = 0, quadrada = 0;

    scanf("%d %d", &linha, &coluna);

    int matriz[linha][coluna];

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] < 0) menor_zero++;
            else if (matriz[i][j] > 0) maior_zero++;
        }
    }

    if (linha == coluna) {
        quadrada = 1;
        for (int i = 0; i < linha; i++) {
            principal += matriz[i][i];
        }
        for (int i = 0, j = coluna - 1; i < linha; i++, j--) {
            secundaria += matriz[i][j];
        }
    }

    printf("Matriz formada:\n");

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            if (j == coluna - 1) printf("%d\n", matriz[i][j]);
            else printf("%d ", matriz[i][j]);
        }
    }

    if (quadrada) {
        printf("A diagonal principal e secundaria tem valor(es) %d e %d respectivamente.\n", principal, secundaria);
    }
    else printf("A diagonal principal e secundaria nao pode ser obtida.\n");

    printf("A matriz possui %d numero(s) menor(es) que zero.\n", menor_zero);
    printf("A matriz possui %d numero(s) maior(es) que zero.\n", maior_zero);

    return 0;
}