#include <stdio.h>

int main() {

    scanf("%*s");

    char genero;
    int nota;
    int acao1, comedia1, suspense1;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao1 = nota;
    else if (genero == 'c') comedia1 = nota;
    else if (genero == 's') suspense1 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao1 = nota;
    else if (genero == 'c') comedia1 = nota;
    else if (genero == 's') suspense1 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao1 = nota;
    else if (genero == 'c') comedia1 = nota;
    else if (genero == 's') suspense1 = nota;

    scanf("%*s");

    int acao2, comedia2, suspense2;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao2 = nota;
    else if (genero == 'c') comedia2 = nota;
    else if (genero == 's') suspense2 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao2 = nota;
    else if (genero == 'c') comedia2 = nota;
    else if (genero == 's') suspense2 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') acao2 = nota;
    else if (genero == 'c') comedia2 = nota;
    else if (genero == 's') suspense2 = nota;

    int peso1, peso2, peso3;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') peso1 = nota;
    else if (genero == 'c') peso2 = nota;
    else if (genero == 's') peso3 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') peso1 = nota;
    else if (genero == 'c') peso2 = nota;
    else if (genero == 's') peso3 = nota;

    scanf(" %c%*s%*c%d", &genero, &nota);
    if (genero == 'a') peso1 = nota;
    else if (genero == 'c') peso2 = nota;
    else if (genero == 's') peso3 = nota;

    int media1 = (acao1 * peso1) + (comedia1 * peso2) + (suspense1 * peso3);
    int media2 = (acao2 * peso1) + (comedia2 * peso2) + (suspense2 * peso3);

    if (media1 >= media2) printf("1\n");
    else printf("2\n");

    return 0;
}