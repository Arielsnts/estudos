#include <stdio.h>

int main() {
    int niveis, amigos;

    scanf("%d %d", &niveis, &amigos);

    int contNiveis[niveis + 1];
    for (int i = 0; i <= niveis; i++) {
        contNiveis[i] = 0;
    }

    for (int i = 0; i < amigos; i++) {
        int a_i;
        scanf("%d", &a_i);

        for (int j = 0; j < a_i; j++) {
            int atualNivel;
            scanf("%d", &atualNivel);
            contNiveis[atualNivel]++;
        }
    }

    int minCompletados = contNiveis[1];
    for (int i = 2; i <= niveis; i++) {
        if (contNiveis[i] < minCompletados) {
            minCompletados = contNiveis[i];
        }
    }

    printf("The %d friends could finish the game %d times\n", amigos, minCompletados);

    return 0;
}