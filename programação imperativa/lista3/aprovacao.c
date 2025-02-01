#include <stdio.h>

int main() {
    int atividades, resolvidas;

    scanf("%d %d", &atividades, &resolvidas);

    float porcResolvidas = (resolvidas * 100.0) / atividades;

    if (porcResolvidas >= 0 && porcResolvidas < 20) printf("%.2f%% 4.40%% Pessimo\n", porcResolvidas);
    else if (porcResolvidas >= 20 && porcResolvidas < 40) printf("%.2f%% 31.65%% Ruim\n", porcResolvidas);
    else if (porcResolvidas >= 40 && porcResolvidas < 60) printf("%.2f%% 56.82%% Bom\n", porcResolvidas);
    else if (porcResolvidas >= 60 && porcResolvidas < 80) printf("%.2f%% 80.00%% Muito bom\n", porcResolvidas);
    else if (porcResolvidas >= 80 && porcResolvidas <= 100) printf("%.2f%% 94.00%% Excelente\n", porcResolvidas);

    return 0;
}