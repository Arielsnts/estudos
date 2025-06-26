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
    printf("\n");
    No* iterador = lista->prox;

    while (iterador != lista) {
        printf("Nome: %s\nCPF: %d\n", iterador->nome, iterador->cpf);
        iterador = iterador->prox;
    }
    printf("\n");
}

No* buscar_pos(No* lista, int pos) {
    No* iterador = lista->prox;
    int cont = 0;

    while(iterador != lista) {
        if (cont == pos) {
            return iterador;
        }
        cont++;
        iterador = iterador->prox;
    }
    return NULL;
}

int remover_pos(No* lista, int pos) {
    No* anterior = lista;
    No* iterador = lista->prox;
    int cont = 0;

    while (iterador != lista) {
        if (cont == pos) {
            anterior->prox = iterador->prox;
            free(iterador);
            return 1;
        }
        anterior = iterador;
        iterador = iterador->prox;
        cont++;
    }
    return 0;
}

void destruir_lista(No* lista) {
    No* iterador = lista->prox;
    No* temp;

    while (iterador != lista) {
        temp = iterador;
        iterador = iterador->prox;
        free(temp);
    }

    free(lista);
}

int main() {
    No* lista = criar_lista();

    int num = 0, pos = 0;
    printf("Digite num e pos: ");
    scanf("%d %d", &num, &pos);

    for (int i = 0; i < num; i++) {
        char nome[11];
        int cpf;

        printf("Nome: ");
        scanf("%s", nome);
        printf("CPF: ");
        scanf("%d", &cpf);

        inserir_inicio(lista, nome, cpf);
    }

    int sobra = num;

    int cont = 0;
    No* iterador = lista->prox;
    No* anterior = lista;

    while (sobra > 1) {
        printf("Participantes atuais:\n");
        exibir_lista(lista);

        for (int i = 0; i < pos;) {
            anterior = iterador;
            iterador = iterador->prox;

            if (iterador == lista) {
                iterador = iterador->prox;
                continue;
            }

            i++;
        }

        anterior->prox = iterador->prox;
        free(iterador);
        iterador = anterior->prox;

        if (iterador == lista) {
            iterador = iterador->prox;
        }

        sobra--;
    }

    printf("Vencedor:\n");
    exibir_lista(lista);

    destruir_lista(lista);
    return 0;
}