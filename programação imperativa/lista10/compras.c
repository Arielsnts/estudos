#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
    float valor;
    int quantidade;
    int ativo;
} Item;

int main() {
    Item lista_itens[100];
    char *func = (char*)malloc(13 * sizeof(char));
    int i = 0;

    while (scanf("%s", func) != EOF) {

        if (strlen(func) == 0) break;

        if (strcmp(func, "INSERIR") == 0) {
            if (i < 100) {
                scanf("%s %f %d", lista_itens[i].nome, &lista_itens[i].valor, &lista_itens[i].quantidade);
                lista_itens[i].ativo = 1;
                i++;
            }
        }
        else if (strcmp(func, "REMOVER") == 0) {
            char nome[51];
            int quantidade = 0;
            scanf("%s %d", nome, &quantidade);

            for (int j = 0; j < i; j++) {
                if (lista_itens[j].ativo && strcmp(nome, lista_itens[j].nome) == 0) {
                    lista_itens[j].quantidade -= quantidade;
                    if (lista_itens[j].quantidade <= 0) {
                        lista_itens[j].ativo = 0;
                    }
                }
            }
        }
        else if (strcmp(func, "REMOVERGRUPO") == 0) {
            int valor = 0;
            scanf("%d", &valor);

            for (int j = 0; j < i; j++) {
                if (lista_itens[j].ativo && lista_itens[j].valor >= valor) {
                    lista_itens[j].valor = 0;
                    lista_itens[j].quantidade = 0;
                    lista_itens[j].ativo = 0;
                }
            }
        }
        else if (strcmp(func, "CONSULTAR") == 0) {
            float soma = 0;
            for (int j = 0; j < i; j++) {
                if (lista_itens[j].ativo) {
                    soma += lista_itens[j].quantidade * lista_itens[j].valor;
                }
            }
            printf("\nAtualmente a lista está em R$%.2f\n", soma);
        }
        else if (strcmp(func, "PROCURAR") == 0) {
            char nome[51];
            scanf("%s", nome);

            int encontrado = 0;

            for (int j = 0; j < i; j++) {
                if (lista_itens[j].ativo && strcmp(lista_itens[j].nome, nome) == 0) {
                    printf("\n%s\n- %.2f\n- %d\n", nome, lista_itens[j].valor, lista_itens[j].quantidade);
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) {
                printf("\n%s nao foi encontrado.\n", nome);
            }
        }
    }

    free(func);
    return 0;
}