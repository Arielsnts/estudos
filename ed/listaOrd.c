#include <stdio.h>
#include <stdlib.h>

int* criar_lista(int capacidade) {
    int* lista = (int*)malloc(capacidade * sizeof(int));
    return lista;
}

void sort(int* lista, int* tamanho) {
    int i, j, chave;

    for (i = 1; i < *tamanho; i++) {
        chave = lista[i];
        j = i - 1;

        while (j >= 0 && lista[j] > chave) {
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = chave;
    }
}

void insere(int** lista, int* tamanho, int* capacidade, int valor) {
    if (*tamanho >= *capacidade) {
        int nova_capacidade = *capacidade * 2;
        int* temp = (int*)realloc(*lista, nova_capacidade * sizeof(int));

        if (temp == NULL) printf("Erro de realocação de memória\n");
        else {
            *lista = temp;
            *capacidade = nova_capacidade;
        }
    }

    if (*tamanho < *capacidade) {
        (*lista)[*tamanho] = valor;
        (*tamanho)++;
        sort(*lista, tamanho);

        printf("Valor %d adicionado com sucesso\n", valor);
    }
}

int busca(int* lista, int tamanho, int valor) {
    int inicio = 0;
    int fim = tamanho - 1;
    int meio;

    while (inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (lista[meio] == valor) {
            printf("Valor %d encontrado na posição %d\n", valor, meio);
            return meio;
        }
        else if (valor > lista[meio]) {
            inicio = meio + 1;
        }
        else {
            fim = meio - 1;
        }
    }

    printf("Valor %d não encontrado\n", valor);
    return -1;
}

// void remove(int* lista, int tamanho, int valor) {

// }

void exibir(int* lista, int tamanho, int capacidade) {
    printf("\nLista com tamanho %d e capacidade %d\n", tamanho, capacidade);
    for (int i = 0; i < tamanho; i++) {
        printf("valor %d: %d\n", i, lista[i]);
    }
}

int main() {
    int capacidade = 4;
    int tamanho = 0;
    int* lista = criar_lista(tamanho);

    insere(&lista, &tamanho, &capacidade, 3);
    insere(&lista, &tamanho, &capacidade, 1);
    insere(&lista, &tamanho, &capacidade, 4);
    insere(&lista, &tamanho, &capacidade, 2);
    insere(&lista, &tamanho, &capacidade, 0);

    exibir(lista, tamanho, capacidade);

    return 0;
}