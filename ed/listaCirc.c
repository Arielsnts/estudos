#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[11];
    int cpf;
    struct No* prox;
} No;

No* criar_lista() {
    No* sentinela = (No*)malloc(sizeof(No));
    sentinela->prox = sentinela;
    
    return sentinela;
}

void inserir_inicio(No* lista, char nome[], int cpf) {
    No* novo_No = (No*)malloc(sizeof(No));
    strcpy(novo_No->nome, nome);
    novo_No->cpf = cpf;
    
    novo_No->prox = lista->prox;
    lista->prox = novo_No;
}

void exibir_lista(No* lista) {
    No* iterador = lista->prox;

    while (iterador != lista) {
        printf("Nome: %s\nCPF: %d\n", iterador->nome, iterador->cpf);
        iterador = iterador->prox;

    }
}

int main() {
    No* lista = criar_lista();

    char nome1[] = "Ariel";
    char nome2[] = "Santos";

    inserir_inicio(lista, nome1, 101010);
    inserir_inicio(lista, nome2, 202020);

    exibir_lista(lista);

    return 0;
}