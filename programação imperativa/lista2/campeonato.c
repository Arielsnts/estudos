#include <stdio.h>

int main() {
    int cVitoria, cEmpate, cSaldo, fVitoria, fEmpate, fSaldo;

    scanf("%d %d %d %d %d %d", &cVitoria, &cEmpate, &cSaldo, &fVitoria, &fEmpate, &fSaldo);

    int cPontos = (cVitoria * 3) + cEmpate;
    int fPontos = (fVitoria * 3) + fEmpate;

    if (cPontos > fPontos) printf("C\n");
    else if (cPontos < fPontos) printf("F\n");
    else {
        if (cSaldo > fSaldo) printf("C\n");
        else if (cSaldo < fSaldo) printf("F\n");
        else {printf("=\n");}
    }

    return 0;
}