#include <stdio.h>

int main() {
    int primeiroFilme;

    int acao1 = 0, comedia1 = 0, suspense1 = 0;
    int acao2 = 0, comedia2 = 0, suspense2 = 0;
    int pesoAcao = 0, pesoComedia = 0, pesoSuspense = 0;

    scanf("Filme%d:%*s\n", &primeiroFilme);

    char genero, genero1, genero2;
    int pontuacao, pontuacao1, pontuacao2;

    scanf(" %c%*[^:]: %d", &genero1, &pontuacao1);
    if (genero1 == 'a') acao1 = pontuacao1;
    else if (genero1 == 'c') comedia1 = pontuacao1;
    else if (genero1 == 's') suspense1 = pontuacao1;

    scanf(" %c%*[^:]: %d", &genero1, &pontuacao1);
    if (genero1 == 'a') acao1 = pontuacao1;
    else if (genero1 == 'c') comedia1 = pontuacao1;
    else if (genero1 == 's') suspense1 = pontuacao1;

    scanf(" %c%*[^:]: %d", &genero1, &pontuacao1);
    if (genero1 == 'a') acao1 = pontuacao1;
    else if (genero1 == 'c') comedia1 = pontuacao1;
    else if (genero1 == 's') suspense1 = pontuacao1;

    int segundoFilme;

    scanf(" Filme%d:%*s\n", &segundoFilme);

    scanf(" %c%*[^:]: %d", &genero2, &pontuacao2);
    if (genero2 == 'a') acao2 = pontuacao2;
    else if (genero2 == 'c') comedia2 = pontuacao2;
    else if (genero2 == 's') suspense2 = pontuacao2;

    scanf(" %c%*[^:]: %d", &genero2, &pontuacao2);
    if (genero2 == 'a') acao2 = pontuacao2;
    else if (genero2 == 'c') comedia2 = pontuacao2;
    else if (genero2 == 's') suspense2 = pontuacao2;

    scanf(" %c%*[^:]: %d", &genero2, &pontuacao2);
    if (genero2 == 'a') acao2 = pontuacao2;
    else if (genero2 == 'c') comedia2 = pontuacao2;
    else if (genero2 == 's') suspense2 = pontuacao2;


    scanf(" %c%*[^:]: %d", &genero, &pontuacao);
    if (genero == 'a') pesoAcao = pontuacao;
    else if (genero == 'c') pesoComedia = pontuacao;
    else if (genero == 's') pesoSuspense = pontuacao;

    scanf(" %c%*[^:]: %d", &genero, &pontuacao);
    if (genero == 'a') pesoAcao = pontuacao;
    else if (genero == 'c') pesoComedia = pontuacao;
    else if (genero == 's') pesoSuspense = pontuacao;

    scanf(" %c%*[^:]: %d", &genero, &pontuacao);
    if (genero == 'a') pesoAcao = pontuacao;
    else if (genero == 'c') pesoComedia = pontuacao;
    else if (genero == 's') pesoSuspense = pontuacao;

    int primeiraPont = (acao1 * pesoAcao) + (comedia1 * pesoComedia) + (suspense1 * pesoSuspense);
    int segundaPont = (acao2 * pesoAcao) + (comedia2 * pesoComedia) + (suspense2 * pesoSuspense);

    if (primeiraPont >= segundaPont) printf("%d\n", primeiroFilme);
    else printf("%d\n", segundoFilme);

    return 0;
}