#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No* proximo;
    struct No* anterior;
} No;

typedef struct Lista {
    No* inicio;
    No* fim;
} Lista;

Lista* criarLista() {
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->inicio = NULL;
    novaLista->fim = NULL;

    return novaLista;
}

void inserir_inicio(Lista** list, int valor) {
    No* novo_No = (No*)malloc(sizeof(No));
    novo_No->elemento = valor;
    novo_No->anterior = NULL;
    novo_No->proximo = NULL;

    Lista* ponteiro = *list;

    if (ponteiro->inicio == NULL) {
        ponteiro->inicio = novo_No;
        ponteiro->fim = novo_No;
    }
    else {
        No* primeiro_No = ponteiro->inicio;

        novo_No->proximo = primeiro_No;
        ponteiro->inicio = novo_No;
        primeiro_No->anterior = novo_No;
    }
}

void inserir_fim(Lista** list, int valor) {
    No* novo_No = (No*)malloc(sizeof(No));
    novo_No->elemento = valor;
    novo_No->anterior = NULL;
    novo_No->proximo = NULL;

    Lista* ponteiro = *list;

    if (ponteiro->fim == NULL) {
        ponteiro->inicio = novo_No;
        ponteiro->fim = novo_No;
    }
    else {
        No* no_ultimo = ponteiro->fim;

        novo_No->anterior = no_ultimo;
        ponteiro->fim = novo_No;
        no_ultimo->proximo = novo_No;
    }
}

void exibir_lista(Lista* list) {
    No* iterador = list->inicio;

    printf("\n");
    while (iterador != NULL) {
        printf("Elemento: %d\n", iterador->elemento);
        iterador = iterador->proximo;
    }
    printf("\n");
}

int main() {
    Lista* list = criarLista();

    inserir_inicio(&list, 5);
    inserir_inicio(&list, 10);

    inserir_fim(&list, 20);
    inserir_fim(&list, 25);

    exibir_lista(list);

    return 0;
}