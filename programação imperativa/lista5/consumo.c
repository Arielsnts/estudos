#include <stdio.h>

int main() {
    int km[100];
    float vol[100];
    char rod[100];

    int contKm;
    int i = 0;
    int cont = 0;
    while (1) {
        scanf("%d%*c", &contKm);
        if (contKm == 0) break;
        scanf(" %f%*c%c", &vol[i], &rod[i]);
        km[i] = contKm;
        i++;
        cont++;
    }

    int distancia = 0;

    for (int j = 0; j < i-1; j++) {
        distancia = distancia + (km[j+1] - km[j]);
    }

    float totalVol = 0;

    for (int j = 1; j < i; j++) {
        totalVol += vol[j];
    }

    float consumoTotal = distancia/totalVol;
    
    float mediaConsumo = 0;
    int distAtual = 0;
    float trechoConsumo = 0;

    for (int j = 0; j < i-1; j++) {
        distAtual = (km[j+1] - km[j]);
        trechoConsumo = distAtual / vol[j+1];

        mediaConsumo += trechoConsumo;
    }

    mediaConsumo /= i - 1;

    float estMediaConsumo = 0;
    int estDistAtual = 0;
    float estTrechoConsumo = 0;
    int contEst = 0;
    
    float cidMediaConsumo = 0;
    int cidDistAtual = 0;
    float cidTrechoConsumo = 0;
    int contCid = 0;

    for (int j = 0; j < i-1; j++) {
        if (rod[j] == 'E') {
            estDistAtual = (km[j+1] - km[j]);
            estTrechoConsumo = estDistAtual / vol[j+1];
    
            estMediaConsumo += estTrechoConsumo;
            contEst++;
        }
        else if (rod[j] == 'C') {
            cidDistAtual = (km[j+1] - km[j]);
            cidTrechoConsumo = cidDistAtual / vol[j+1];
    
            cidMediaConsumo += cidTrechoConsumo;
            contCid++;
        }
    }
    

    estMediaConsumo /= contEst;
    cidMediaConsumo /= contCid;

    printf("Consumo Total: %.2f km/lt\n", consumoTotal);
    printf("Media entre os abastecimentos: %.2f km/lt\n", mediaConsumo);
    if (contEst != 0) printf("Media em estrada: %.2f km/lt\n", estMediaConsumo);
    else printf("Nao rodou em estrada\n");
    if (contCid != 0) printf("Media em cidade: %.2f km/lt\n", cidMediaConsumo);
    else printf("Nao rodou em cidade\n");

    return 0;
}
