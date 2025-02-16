#include <stdio.h>

int main() {
    int popIni, anoIni, q, anoFinal;
    
    scanf("%d%*c%d%*c%d%*c%d", &popIni, &anoIni, &q, &anoFinal);

    int quantAno = anoFinal - anoIni;

    int listaPop[quantAno];

    listaPop[0] = popIni;

    float percentual = ((float) q / 100) + 1.0;

    int novaPop = popIni;

    for (int i = 1; i <= quantAno; i++) {
        novaPop *= percentual;
        listaPop[i] = novaPop;
    }

    for (int i = 0; i <= quantAno; i++) {
        printf("%d %d\n", anoIni, listaPop[i]);
        anoIni++;
    }

    return 0;
}