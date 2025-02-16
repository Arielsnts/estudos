#include <stdio.h>

int main() {
    int numNotas, soma = 0;

    scanf("%d", &numNotas);

    int listaNotas[numNotas];
    
    for (int i = 0; i < numNotas; i++) {
        scanf("%d", &listaNotas[i]);
        soma += listaNotas[i];
    }
    
    int n0=0, n1=0, n2=0, n3=0, n4=0, n5=0, n6=0, n7=0, n8=0, n9=0, n10=0;
    
    for (int i = 0; i < numNotas; i++) {
        if (listaNotas[i] == 0) n0++;
        else if (listaNotas[i] == 1) n1++;
        else if (listaNotas[i] == 2) n2++;
        else if (listaNotas[i] == 3) n3++;
        else if (listaNotas[i] == 4) n4++;
        else if (listaNotas[i] == 5) n5++;
        else if (listaNotas[i] == 6) n6++;
        else if (listaNotas[i] == 7) n7++;
        else if (listaNotas[i] == 8) n8++;
        else if (listaNotas[i] == 9) n9++;
        else if (listaNotas[i] == 10) n10++;
    }

    float media = (float) soma / numNotas;
    
    float mediana;

    int i = 0;
    while (i < numNotas - 1) {
        int j = i + 1;
        while (j < numNotas) {
            if (listaNotas[i] > listaNotas[j]) {
                int temp = listaNotas[i];
                listaNotas[i] = listaNotas[j];
                listaNotas[j] = temp;
            }
            j++;
        }
        i++;
    }

    if (numNotas % 2 == 1) {
        mediana = listaNotas[numNotas/2];
    } else {
        mediana = ((listaNotas[numNotas/2] + listaNotas[numNotas/2-1]) / 2.0);
    }

    int frequencias[11] = {n0, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10};
    int maxFreq = 0, moda = -1, countModa = 0;
    i = 0;

    while (i <= 10) {
        if (frequencias[i] > maxFreq) {
            maxFreq = frequencias[i];
            moda = i;
            countModa = 1;
        } else if (frequencias[i] == maxFreq && maxFreq > 1) {
            countModa++;
        }
        i++;
    }
    
    
    printf("Media: %.2f\nMediana: %.2f\n", media, mediana);
    if (countModa > 1 || maxFreq == 1) {
        printf("Nao tem moda\n");
    } else {
        printf("Moda: %.2f\n", (float) moda);
    }

    return 0;
}
