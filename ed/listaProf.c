#include <stdio.h>
#include <stdlib.h>

// Registro que representa um nó da lista.
typedef struct
{
    int chave; // Chave do nó.
    char campo_1;
    float campo_2;
} No;

// Cria um array com alocação dinâmica cujos elementos são do tipo No.
// Retorna um ponteiro para o início de um array de elementos do tipo No.
No* criar_lista(int capacidade_inicial)
{
    No* lista = (No*) malloc(capacidade_inicial * sizeof(No));
    if (lista == NULL)
    {
        printf("Erro na alocação de memória!\n");
    }
    return lista;
}

// Libera a memória alocada para a lista
void destruir_lista(No *lista)
{
	free(lista);
	printf("Lista destruída com sucesso\n");
}

// Busca a posição do primeiro nó com a chave fornecida.
// Se há um elemento com a chave, retorna a posição do elemento.
// Caso contrário, retorna -1.
int buscar_no(No* lista, int tamanho, int valor_chave)
{
	int i = 0;
	while(i < tamanho && lista[i].chave != valor_chave)
	{
		i++;
	}
	
	if(i == tamanho)
	{
		printf("Não há elemento com a chave %d\n", valor_chave);
		return -1;
	}
	else
	{
		printf("Elemento com chave %d encontrado na posição %d\n", valor_chave, i);
		return i;
	}    
}

// Insere um nó no final da lista.
// Se necessário realoca o array, dobrando a capacidade.
// ATENÇÃO: analise com cuidado os tipos dos parâmetros.
// Por que usamos 'int *tamanho' (com um asterisco) em vez de 'int tamanho' (sem asterisco)?
// Por que usamos 'int *capacidade' (com um asterisco) em vez de 'int capacidade' (sem asterisco)?
// Por que usamos 'No** lista' (com dois asteriscos) em vez de 'No* lista' (com um asterisco)?
void insere(No** lista, int *tamanho, int *capacidade, int valor_chave, char valor_campo_1, float valor_campo_2)
{		
	// Checa se o tamanho da lista atingiu a memória alocada para o array. Se atingiu, dobra a capacidade do array via realloc.
    if (*tamanho == *capacidade)
    {
        int nova_capacidade = *capacidade * 2;
        No* temp = (No*) realloc(*lista, nova_capacidade * sizeof(No));
        if (*lista == NULL)
        {
            printf("Erro na realocação de memória!\n");
        }
        else
        {
			(*lista) = temp;
			*capacidade = nova_capacidade;
		}
    }
    
    // Inserção dos dados no novo nó (localizado mais à direita).
    if(*tamanho < *capacidade)
    {
		(*lista)[*tamanho].chave = valor_chave;
		(*lista)[*tamanho].campo_1 = valor_campo_1;
		(*lista)[*tamanho].campo_2 = valor_campo_2;
		printf("Novo elemento com chave %d inserido na posição %d\n", valor_chave, *tamanho);
		(*tamanho)++;
	}
}

// Remove um nó que tenha a chave fornecida.
// ATENÇÃO: analise com cuidado os tipos dos parâmetros.
// Por que usamos 'int *tamanho' (com um asterisco) em vez de 'int tamanho' (sem asterisco)?
void remover_no(No* lista, int* tamanho, int valor_chave)
{	
	// Busca por um nó com a chave fornecida.
	// Se existir, efetua a remoção.
    int pos = buscar_no(lista, *tamanho, valor_chave); 
    if (pos > -1)
    {
		// Sobrescreve o elemento encontrado pelo último.
		// Reduz o tamanho da lista.
		lista[pos] = lista[*tamanho-1];
		printf("Nó com chave %d na posição %d removido\n", valor_chave, pos);
		(*tamanho)--;
	}
}

// Exibe a lista.
void exibir_lista(No* lista, int tamanho, int capacidade)
{
    printf("\nLista (tamanho: %d, capacidade: %d):\n", tamanho, capacidade);
    for (int i = 0; i < tamanho; i++)
    {
        printf("posicao: %d, chave: %d, campo_1: %c, campo_2: %.2f\n", i, lista[i].chave, lista[i].campo_1, lista[i].campo_2);
    }
    printf("\n");
}

int main() {
	// Capacidade inicial de 4 elementos
	// Tamanho inicial igual a 0, isto é, a lista começa vazia.
    int capacidade = 4;
    int tamanho = 0;
    No* lista = criar_lista(capacidade);

	// ATENÇÃO: analise com cuidado os valores que são passados como argumentos das funções.
	// Por que às vezes passamos o endereço de memória da variável (&nome_da_variavel)? Atente-se às assinaturas das funções em questão.
	
    insere(&lista, &tamanho, &capacidade, 10, 'A', 1.1);
    insere(&lista, &tamanho, &capacidade, 50, 'E', 5.5);
	insere(&lista, &tamanho, &capacidade, 20, 'B', 2.2);
	insere(&lista, &tamanho, &capacidade, 40, 'D', 4.4);
	
	exibir_lista(lista, tamanho, capacidade);
	
	insere(&lista, &tamanho, &capacidade, 30, 'C', 3.3);

    exibir_lista(lista, tamanho, capacidade);
    
    buscar_no(lista, tamanho, 40);
    
    exibir_lista(lista, tamanho, capacidade);
    
    remover_no(lista, &tamanho, 50);
    
    exibir_lista(lista, tamanho, capacidade);
    
    remover_no(lista, &tamanho, 99);
    
    exibir_lista(lista, tamanho, capacidade);
    
    destruir_lista(lista);
    
    return 0;
}