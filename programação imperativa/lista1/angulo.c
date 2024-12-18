#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float angulo1;
    float angulo2;

    scanf("%f", &angulo1);
    scanf("%f", &angulo2);

    float angulo3 = 180 - (angulo1 + angulo2);

    printf("3o angulo=%.6f\n", angulo3);
	return 0;
}