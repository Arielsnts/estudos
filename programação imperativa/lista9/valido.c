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

    int saida = 0;
    
    for (int x = 0; x < linhas - 1; x++) {
        for (int y = 0; y < colunas - 1; y++) {
            int frequencia[4] = {0, 0, 0, 0}; 

            int valores[4] = {
                matriz[x][y], matriz[x][y + 1], 
                matriz[x + 1][y], matriz[x + 1][y + 1]
            };

            for (int i = 0; i < 4; i++) {
                if (valores[i] >= 0 && valores[i] <= 3) {
                    frequencia[valores[i]] = 1;
                }
            }

            if (frequencia[0] && frequencia[1] && frequencia[2] && frequencia[3]) {
                saida++;
            }
        }
    }

    printf("%d\n", saida);
    return 0;
}
