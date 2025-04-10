#include <stdio.h>
#include <stdlib.h>

int quadrado(int x) {
   return x *= x;
}

int main() {

    int *arr = (int*)malloc(5 * sizeof(int));

    int **matriz = (int**)malloc(5 * sizeof(int*));

    for (int i = 0; i < 5; i++) {
        matriz[i] = (int*)malloc(2 * sizeof(int));
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            matriz[i][j] = quadrado(i) + quadrado(j);
            printf("%.3d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 5; i++) {
        arr[i] = quadrado(i);
        printf("%d\n", arr[i]);
    }

    return 0; 
}