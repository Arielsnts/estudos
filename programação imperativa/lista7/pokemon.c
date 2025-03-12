#include <stdio.h>
#include <string.h>

struct Pokemon
{
    char nome[30];
    int id;
    int ataque;
    int vida;
};

int main() {
    struct Pokemon red[6];

    for (int i = 0; i < 6; i++) {
        scanf("%s", red[i].nome);
        scanf("%d", &red[i].id);
        scanf("%d", &red[i].ataque);
        scanf("%d", &red[i].vida);
    }

    char escolha_Red[30];
    int indexRed = 0;
    int maiorAtaque = red[0].ataque;
    int menorID = red[0].id;

    for (int i = 1; i < 6; i++) {
        if (red[i].ataque > maiorAtaque) {
            maiorAtaque = red[i].ataque;
            indexRed = i;
            menorID = red[i].id;
        } else if (red[i].ataque == maiorAtaque) {
            if (red[i].id < menorID) {
                indexRed = i;
                menorID = red[i].id;
            }
        }
    }

    strcpy(escolha_Red, red[indexRed].nome);

    struct Pokemon blue[6];

    for (int i = 0; i < 6; i++) {
        scanf("%s", blue[i].nome);
        scanf("%d", &blue[i].id);
        scanf("%d", &blue[i].ataque);
        scanf("%d", &blue[i].vida);
    }

    char escolha_Blue[30];
    int indexBlue = 0;
    maiorAtaque = blue[0].ataque;
    menorID = blue[0].id;

    for (int i = 1; i < 6; i++) {
        if (blue[i].ataque > maiorAtaque) {
            maiorAtaque = blue[i].ataque;
            indexBlue = i;
            menorID = blue[i].id;
        } else if (blue[i].ataque == maiorAtaque) {
            if (blue[i].id < menorID) {
                indexBlue = i;
                menorID = blue[i].id;
            }
        }
    }

    strcpy(escolha_Blue, blue[indexBlue].nome);
    
    printf("Pokemon do Red: %s\n", escolha_Red);
    printf("Pokemon do Blue: %s\n", escolha_Blue);

    while (1) {
        if (red[indexRed].vida <= 0 && blue[indexBlue].vida <= 0) {
            printf("Empate\n");
            break;
        }
        else if (red[indexRed].vida <= 0) {
            printf("Vencedor: Blue\n");
            break;
        }
        else if (blue[indexBlue].vida <= 0) {
            printf("Vencedor: Red\n");
            break;
        }

        red[indexRed].vida -= blue[indexBlue].ataque;
        blue[indexBlue].vida -= red[indexRed].ataque;
    }
    

    return 0;
}
