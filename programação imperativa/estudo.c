#include <stdio.h>
#include <stdlib.h>

int quadrado(int *num) {
    return *num *= *num;
}

typedef char* str;

int main() {
    int linhas = 2, colunas = 3;

    int **matriz = (int**)malloc(linhas * sizeof(int));

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
    }

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = quadrado(&j);
        }
    }

    for (int i = 0; i < linhas; i++) {
        printf("%d %d %d\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }

    return 0; 
}