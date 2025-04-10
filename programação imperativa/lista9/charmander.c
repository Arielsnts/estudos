#include <stdio.h>

int main() {
    float matriz[12][8];

    float menorChance = 0;

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%f", &matriz[i][j]);
            if (i == 0 && j == 0) menorChance = matriz[i][j];
            else if (menorChance > matriz[i][j]) menorChance = matriz[i][j];
        }
    }

    if (menorChance > 0.5) {
        printf("Proximo ano eu tento denovo...");
        return 0;
    }

    int mes = 0, dia = 0;
    int encontrado = 0;
    
    for (int i = 0; i < 12 && !encontrado; i++) {
        for (int j = 0; j < 8; j++) {
            if (matriz[i][j] == menorChance) {
                mes = i;
                dia = j;
                encontrado = 1;
                break;
            }
        }
    }

    // printf("%d %d\n", mes, dia);
    char *sMes;
    char *sDia;
    char *sOrdem;
    
    if (mes == 0) sMes = "Janeiro";
    else if (mes == 1) sMes = "Fevereiro";
    else if (mes == 2) sMes = "Março";
    else if (mes == 3) sMes = "Abril";
    else if (mes == 4) sMes = "Maio";
    else if (mes == 5) sMes = "Junho";
    else if (mes == 6) sMes = "Julho";
    else if (mes == 7) sMes = "Agosto";
    else if (mes == 8) sMes = "Setembro";
    else if (mes == 9) sMes = "Outubro";
    else if (mes == 10) sMes = "Novembro";
    else if (mes == 11) sMes = "Dezembro";
    
    if (dia % 2 == 0) sDia = "Sabado";
    else sDia = "Domingo";
    
    int ordem = dia / 2;
    if (ordem == 0) sOrdem = "Primeiro";
    else if (ordem == 1) sOrdem = "Segundo";
    else if (ordem == 2) sOrdem = "Terceiro";
    else if (ordem == 3) sOrdem = "Quarto";    

    printf("O melhor dia e no %s %s de %s\n", sOrdem, sDia, sMes);

    return 0;
}