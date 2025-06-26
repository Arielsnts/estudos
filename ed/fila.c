#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int elemento;
    struct No* prox;
} No;

No* create() {
    return NULL;
}

int isEmpty(No* fila) {
    if (fila == NULL) return 1;
    else return 0;
}

void enqueue(No** fila, int valor) {
    No* novo_No = (No*)malloc(sizeof(No));
    novo_No->elemento = valor;

    if (isEmpty(*fila)) {
        novo_No->prox = *fila;
        *fila = novo_No;
    }
    else {
        No* iterador = *fila;

        while (iterador->prox != NULL) {
            iterador = iterador->prox;
        }

        iterador->prox = novo_No;
        novo_No->prox = NULL;
    }
}

void dequeue(No** fila) {
    No* primeiro_No = *fila;
    *fila = primeiro_No->prox;
    free(primeiro_No);
}

No* first(No** fila) {
    if (isEmpty(*fila)) return NULL;

    No* primeiro_No = *fila;
    return primeiro_No;
}

void clear(No** pilha) {
    No* iterador = *pilha;

    while (*pilha != NULL) {
        *pilha = iterador->prox;
        free(iterador);
        iterador = *pilha;
    }
}

int main() {
    No* fila = create();

    enqueue(&fila, 5);
    enqueue(&fila, 10);
    enqueue(&fila, 15);

    No* primeiro = first(&fila);

    printf("%d\n", primeiro->elemento);

    clear(&fila);
    return 0;
}