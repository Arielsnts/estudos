#include <stdio.h>
#include <string.h>

struct Lista
{
    char nome[51];
    char numero[15];
    int vinculo;
};

int main() {
    int numCadastro = 0;

    scanf("%d\n", &numCadastro);

    struct Lista contato[50];

    for (int i = 0; i < numCadastro; i++) {
        fgets(contato[i].nome, 51, stdin);
        contato[i].nome[strcspn(contato[i].nome, "\n")] = 0;

        fgets(contato[i].numero, 15, stdin);
        contato[i].numero[strcspn(contato[i].numero, "\n")] = 0;

        scanf("%d\n", &contato[i].vinculo);
    }

    char pesquisa[51];

    while (1) {
        fgets(pesquisa, 51, stdin);
        pesquisa[strcspn(pesquisa, "\n")] = 0;

        if (strcmp(pesquisa, "#") == 0) break;

        int encontrado = 0;

        for (int i = 0; i < numCadastro; i++) {
            if (strncmp(contato[i].nome, pesquisa, strlen(pesquisa)) == 0) { 
                printf("Nome: %s\n", contato[i].nome);
                printf("Numero: %s\n", contato[i].numero);
                if (contato[i].vinculo == 1) printf("Vinculo: Familia\n\n");
                else if (contato[i].vinculo == 2) printf("Vinculo: Faculdade\n\n");
                else if (contato[i].vinculo == 3) printf("Vinculo: Amigo\n\n");

                encontrado = 1;
            }
        }

        if (!encontrado) {
            printf("%s nao foi cadastrado\n", pesquisa);
        }
    }

    return 0;
}
