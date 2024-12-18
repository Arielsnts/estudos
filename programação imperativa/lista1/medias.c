#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float nota1;
    float nota2;
    float nota3;

    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    float media = (nota1 + nota2 + nota3) / 3;
    float mediaPonderada1 = ((nota1 * 2) + (nota2 * 2) + (nota3 * 3)) / 7;
    float mediaPonderada2 = (nota1 + (nota2 * 2) + (nota3 * 2)) / 5;

    printf("%.2f\n", media);
    printf("%.2f\n", mediaPonderada1);
    printf("%.2f\n", mediaPonderada2);

	return 0;
}