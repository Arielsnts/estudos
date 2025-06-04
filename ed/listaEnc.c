#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No* prox;
} No;

void inserir_inicio(No** lista, int valor) {
    No* novo_No = (No*)malloc(sizeof(No));

    novo_No->elemento = valor;
    novo_No->prox = *lista;
    *lista = novo_No;
}

void inserir_pos(No** lista, int valor, int pos) {
    No* novo_No = (No*)malloc(sizeof(No));
    novo_No->elemento = valor;

    if (pos == 0) {
        novo_No->prox = *lista;
        *lista = novo_No;
        return;
    }

    No* i = *lista;
    No* anterior = NULL;
    int cont = 0;

    while (i != NULL && cont < pos) {
        anterior = i;
        i = i->prox;
        cont++;
    }

    if (cont == pos) {
        anterior->prox = novo_No;
        novo_No->prox = i;
    } else {
        printf("Posição inválida\n");
        free(novo_No);
    }
}

void exibir(No* lista) {
    No* i = lista;
    if (i == NULL) {
        printf("Lista vazia\n");
        return;
    }
    printf("\nLISTA ENCADEADA\n");
    while (i != NULL) {
        printf("Valor: %d\n", i->elemento);
        i = i->prox;
    }
}

int buscar(No* lista, int valor) {
    No* i = lista;
    int cont = 0;
    while (i != NULL) {
        if (i->elemento == valor) {
            printf("Valor %d encontrado na posição %d\n", valor, cont);
            return cont;
        }
        i = i->prox;
        cont++;
    }
    printf("Valor %d não encontrado\n", valor);
    return -1;
}

void remover_valor(No** lista, int valor) {
    No* i = *lista;
    No* anterior = NULL;
    while (i != NULL) {
        if (i->elemento == valor) {
            if (anterior == NULL) {
                *lista = i->prox;
            }
            else {
                anterior->prox = i->prox;
            }
            printf("Elemento %d foi removido\n", valor);
            free(i);
            return;
        }
        anterior = i;
        i = i->prox;
    }
    printf("Elemento não encontrado\n");
}

void remover_posicao(No** lista, int pos) {
    No* i = *lista;
    No* anterior = NULL;
    int cont = 0;
    while (i != NULL) {
        if (cont == pos) {
            if (anterior == NULL) {
                *lista = i->prox;
            }
            else {
                anterior->prox = i->prox;
            }
            printf("Elemento %d foi removido na posição %d\n", i->elemento, pos);
            free(i);
            return;
        }
        anterior = i;
        i = i->prox;
        cont++;
    }
    printf("Posição %d é inválida\n", pos);
    return;
}

void destruir(No** lista) {
    No* i = *lista;
    No* sucessor = NULL;
    while (i != NULL) {
        sucessor = i->prox;
        free(i);
        i = sucessor;
    }

    *lista = NULL;
    printf("Lista destruída\n");
    return;
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 2);
    inserir_pos(&lista, 4, 2);
    inserir_pos(&lista, 1, 3);
    inserir_pos(&lista, 10, 10);

    remover_posicao(&lista, 3);
    remover_valor(&lista, 4);

    exibir(lista);
}