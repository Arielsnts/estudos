#include <stdio.h>

int main() {
    char atividade;
    float horas;
    char area, justificativa;

    scanf("%c%*s%*c%f%*c%c%*s%*c%c", &atividade, &horas, &area, &justificativa);

    if (area == 'c') {
        if (atividade == 'c' || atividade == 'm') {
            if (horas >= 12.0) printf("ACEITA");
            else printf("REJEITADA");
        }
        else if (atividade == 's' && horas >= 1.0) printf("ACEITA");
        else printf("REJEITADA");
    }
    else if (area == 'o' && justificativa == 'S') {
        if (atividade == 'c' || atividade == 'm') {
            if (horas >= 12.0) printf("ACEITA");
            else printf("REJEITADA");
        }
        else if (atividade == 's' && horas >= 1.0) printf("ACEITA");
        else printf("REJEITADA\n");
    }
    else printf("REJEITADA\n");

    return 0;
}
