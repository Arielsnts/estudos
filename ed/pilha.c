#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int elemento;
    struct No* prox;
} No;

No* create() {
    return NULL;
}

int isEmpty(No* pilha) {
    if (pilha == NULL) return 1;
    else return 0;
}

void push(No** pilha, int valor) {
    No* novo_No = (No*)malloc(sizeof(No));
    novo_No->elemento = valor;

    novo_No->prox = *pilha;
    *pilha = novo_No;
}

void pop(No** pilha) {
    if (isEmpty(*pilha)) return;

    No* primeiro_No = *pilha;
    No* segundo_No = primeiro_No->prox;

    *pilha = segundo_No;
    free(primeiro_No);
}

int top(No* pilha) {
    if (isEmpty(pilha)) return -1;

    No* no = pilha;

    return no->elemento;
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
    No* pilha = create();
    
    push(&pilha, 5);
    push(&pilha, 10);

    printf("%d\n", top(pilha));

    pop(&pilha);

    printf("%d\n", top(pilha));

    push(&pilha, 15);

    printf("%d\n", top(pilha));

    return 0;
}