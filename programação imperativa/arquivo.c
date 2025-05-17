#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "a+");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char nome[21];
    char numero[12];
    int esc = 0;

    printf("-----Agenda-----");
    
    while (1) {
        printf("\nQuer adicionar um contato? [1/0] ");
        scanf("%d", &esc);
        while (getchar() != '\n');

        if (esc < 0 || esc > 1) {
            printf("ERRO!");
            continue;
        }
    
        if (esc == 1) {
            printf("\nDigite o nome:\n");
            fgets(nome, 21, stdin);
            nome[strcspn(nome, "\n")] = '\0';
        
            printf("Digite o número:\n");
            fgets(numero, 12, stdin);
        
            fprintf(arquivo, "\n%s/%s", nome, numero);
        }
        else if (esc == 0) break;
    }

    rewind(arquivo);

    int c;

    printf("\nLista de contatos:");
    while (1) {
        printf("\n\nNome: ");
        while ((c = fgetc(arquivo)) != EOF && c != '/' && c != '\n') {
            putchar(c);
        }
        if (c == EOF || c == '\n') {
            break;
        }
        printf("\nNúmero: ");
        while ((c = fgetc(arquivo)) != EOF && c != '\n') {
            putchar(c);
        }

        if (c == EOF) {
            break;
        }
    }

    fclose(arquivo);

    printf("\n\nExecutado com sucesso!\n");

    return 0;
}