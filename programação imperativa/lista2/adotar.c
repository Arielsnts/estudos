#include <stdio.h>

int main() {
    int idadeAdotante, idadeAdotado;
    char ascendente, conjunta, casado, paiDesconhecido, consentimentoPai, consentimentoAdotado;

    scanf("%d %c %c %c %d %c %c %c",
        &idadeAdotante,
        &ascendente,
        &conjunta,
        &casado,
        &idadeAdotado,
        &paiDesconhecido,
        &consentimentoPai,
        &consentimentoAdotado);

    int diferencaIdade = idadeAdotante - idadeAdotado;

    if (ascendente == 'S') {
        printf("Nao pode adotar\n");
        return 0;
    }

    if (idadeAdotante < 18 || diferencaIdade < 16) {
        printf("Nao pode adotar\n");
        return 0;
    }

    if (conjunta == 'S' && casado == 'N') {
        printf("Nao pode adotar\n");
        return 0;
    }

    if (paiDesconhecido == 'N' && consentimentoPai == 'N') {
        printf("Nao pode adotar\n");
        return 0;
    }

    if (idadeAdotado > 12 && consentimentoAdotado == 'N') {
        printf("Nao pode adotar\n");
        return 0;
    }

    printf("Pode adotar\n");
    return 0;
}