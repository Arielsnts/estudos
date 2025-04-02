#include <stdio.h>

int main() {
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);

    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int x_pos, y_pos;
    scanf("%d %d", &x_pos, &y_pos);

    int k_mov;
    scanf("%d", &k_mov);

    int soma = 0;

    for (int i = 0; i < k_mov; i++) {
        int comando;
        scanf("%d", &comando);

        if (comando == 0) {
            if (x_pos + 1 < linhas && y_pos - 1 >= 0) {
                x_pos++;
                y_pos--;
            }
        } else if (comando == 1) {
            if (x_pos - 1 >= 0 && y_pos - 1 >= 0) {
                x_pos--;
                y_pos--;
            }
        } else if (comando == 2) {
            if (x_pos + 1 < linhas && y_pos + 1 < colunas) {
                x_pos++;
                y_pos++;
            }
        } else if (comando == 3) {
            if (x_pos - 1 >= 0 && y_pos + 1 < colunas) {
                x_pos--;
                y_pos++;
            }
        }
        soma += matriz[x_pos][y_pos];
    }

    printf("%d\n", soma);
    return 0;
}
