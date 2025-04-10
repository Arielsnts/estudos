#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct cadastro{
	char nome[50];
	char nasc[15];
	char cidade[50];
	int idade;
};
typedef struct cadastro cadastro;

void gerarsenha(cadastro f, char senha[]){
	char pnome[6] = "", pnasc[5], pcidade[5] = "";
	int i=0,j=0;
	
int nome_len = 0;
    while (f.nome[i] != ' ' && f.nome[i] != '\0' && nome_len < 5) {
        if (isalpha(f.nome[i])) {
            pnome[nome_len++] = f.nome[i];
        }
        i++;
    }
    pnome[nome_len] = '\0';
    
int cidade_len = 0;
    i = 0;
    while (f.cidade[i] != '\0' && cidade_len < 4) {
        if (isalpha(f.cidade[i])) {
            pcidade[cidade_len++] = f.cidade[i];
        }
        i++;
    }
    pcidade[cidade_len] = '\0';
	
	pnasc[0] = f.nasc[0];
	pnasc[1] = f.nasc[1];
	pnasc[2] = f.nasc[3];
	pnasc[3] = f.nasc[4];
	pnasc[4] = '\0';
	
 for (i = 0; i < 5; i++) {
        if (pnome[i] != '\0') senha[j++] = pnome[i];
        if (i < 4 && pnasc[i] != '\0') senha[j++] = pnasc[i];
        if (i < 4 && pcidade[i] != '\0') senha[j++] = pcidade[i];
    }
	
	senha[j++] = (f.idade/10) + '0';
	senha[j++] = (f.idade%10) + '0';
	senha[j] = '\0';
	
}

int main(){
	
	cadastro funcionario[5];
	
	int i = 0;
	
	char senha[30];
	
	while(i<5){
	scanf("%[^\n]", funcionario[i].nome);
	getchar();
		if(strcmp(funcionario[i].nome, "SAIR") == 0) break;
			
	scanf("%[^\n]", funcionario[i].nasc);
	getchar();
	scanf("%[^\n]", funcionario[i].cidade);
	getchar();
	scanf("%d", &funcionario[i].idade);
	getchar();
	
	gerarsenha(funcionario[i], senha);

        printf("Nome: %s\n", funcionario[i].nome);
        printf("Data de Nascimento: %s\n", funcionario[i].nasc);
        printf("Cidade Natal: %s\n", funcionario[i].cidade);
        printf("Idade: %d anos\n", funcionario[i].idade);
        printf("Senha: %s\n\n", senha);
		
		i++;
	}
	
}