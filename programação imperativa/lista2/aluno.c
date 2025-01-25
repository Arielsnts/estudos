#include <stdio.h>

int main() {
    float media;
    int aulas, faltas;

    scanf("%f %d %d", &media, &aulas, &faltas);

    float maxFaltas75 = aulas - (0.75 * aulas);
    float maxFaltas50 = aulas - (0.5 * aulas);

    if (media >= 7.0 && faltas <= maxFaltas50) {
        printf("APROVADO\n");
    } else if (media >= 5.0 && faltas <= maxFaltas75) {
        printf("APROVADO\n");
    } else printf("REPROVADO\n");

    return 0;
}
