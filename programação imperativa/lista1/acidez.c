#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    float entrada;
    scanf("%f", &entrada);

    if (entrada < 7) printf("Acida\n");
    else if (entrada > 7) printf("Basica\n");
    else printf("Neutra\n");
    
	return 0;
}
