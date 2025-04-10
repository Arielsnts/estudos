#include <stdio.h>
#include <math.h>

int verQuadrado(int n, int matriz[n][n]) {
    int raiz = (int)sqrt(n);

    for (int lin = 0; lin < n; lin += raiz) {
        for (int col = 0; col < n; col += raiz) {

            int freq[n + 1];
            for (int i = 1; i <= n; i++) freq[i] = 0;

            for (int i = lin; i < lin + raiz; i++) {
                for (int j = col; j < col + raiz; j++) {
                    int val = matriz[i][j];
                    if (val < 1 || val > n) return 0;
                    if (freq[val] != 0) return 0;
                    freq[val] = 1;
                }
            }
        }
    }

    return 1;
}

int verLinha(int n, int matriz[n][n]) {
    for (int lin = 0; lin < n; lin++) {
        int freq[n + 1];
        for (int i = 1; i <= n; i++) freq[i] = 0;

        for (int col = 0; col < n; col++) {
            int val = matriz[lin][col];
            if (val < 1 || val > n) return 0;
            if (freq[val] != 0) return 0;
            freq[val] = 1;
        }
    }

    return 1;
}

int verColuna(int n, int matriz[n][n]) {
    for (int col = 0; col < n; col++) {
        int freq[n + 1];
        for (int i = 1; i <= n; i++) freq[i] = 0;

        for (int lin = 0; lin < n; lin++) {
            int val = matriz[lin][col];
            if (val < 1 || val > n) return 0;
            if (freq[val] != 0) return 0;
            freq[val] = 1;
        }
    }

    return 1;
}

int main() {
    int n = 0;
    scanf("%d", &n);

    int matriz[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int subquadrados = verQuadrado(n, matriz);
    int linhas = verLinha(n, matriz);
    int colunas = verColuna(n, matriz);

    if (subquadrados && linhas && colunas) printf("YES\n");
    else printf("NO\n");

    return 0;
}