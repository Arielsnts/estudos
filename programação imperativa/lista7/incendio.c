#include <stdio.h>

int main() {
    int numTestes = 0;
    
    scanf("%d", &numTestes);

    for (int teste = 1; teste <= numTestes; teste++) {
        float soma = 0.0, media = 0.0;
        int numSprinkler = 0;

        scanf("%d", &numSprinkler);

        int id[numSprinkler];
        float temp[numSprinkler];
        char fumaca[numSprinkler];

        for (int i = 0; i < numSprinkler; i++) {
            scanf("%d%*c%f%*c%c", &id[i], &temp[i], &fumaca[i]);
            soma += temp[i];
        }

        media = soma / numSprinkler;

        printf("TESTE %d\n", teste);

        for (int i = 0; i < numSprinkler; i++) {
            if (fumaca[i] == 'S' || temp[i] > 40.0 || temp[i] > media * 1.15) {
                printf("%d\n", id[i]);
            }
        }
    }
}