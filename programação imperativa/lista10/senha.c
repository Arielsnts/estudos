#include <stdio.h>
#include <string.h>

typedef struct empresa {
    char nome[51];
    char nasc[11];
    char cidade[51];
    int idade;
    char senha[20];
} Empresa;

char* criarSenha(Empresa func) {
    static char senha[100] = "";
    int i = 0, j = 0;

    char nome[6] = "";
    strncpy(nome, func.nome, 5);

    char cidade[5] = "";
    strncpy(cidade, func.cidade, 4);

    char dia[3] = "";
    char mes[3] = "";
    strncpy(dia, func.nasc, 2);
    strncpy(mes, func.nasc + 3, 2);

    while (i < 5 || j < 4) {
        if (i < 5 && nome[i] != '\0') {
            strncat(senha, &nome[i], 1);
        }
        if (i < 2 && dia[i] != '\0') {
            strncat(senha, &dia[i], 1);
        } else if (i >= 2 && i - 2 < 2 && mes[i - 2] != '\0') {
            strncat(senha, &mes[i - 2], 1);
        }
        if (j < 4 && cidade[j] != '\0') {
            strncat(senha, &cidade[j], 1);
        }
        i++;
        j++;
    }

    char idadeStr[10];
    sprintf(idadeStr, "%d", func.idade);
    strcat(senha, idadeStr);

    return senha;
}

int main() {
    Empresa funcionario[5];
    int i = 0;

    for (i; i < 5; i++) {
        char linha[100];
        fgets(linha, sizeof(linha), stdin);
        linha[strcspn(linha, "\n")] = '\0';
        if (strncmp(linha, "SAIR", 4) == 0) break;
        strcpy(funcionario[i].nome, linha);

        fgets(funcionario[i].nasc, 11, stdin);
        funcionario[i].nasc[strcspn(funcionario[i].nasc, "\n")] = '\0';
        getchar();

        fgets(funcionario[i].cidade, 51, stdin);
        funcionario[i].cidade[strcspn(funcionario[i].cidade, "\n")] = '\0';

        scanf("%d", &funcionario[i].idade);
        getchar();

        strcpy(funcionario[i].senha, criarSenha(funcionario[i]));
    }

    for (int j = 0; j < i; j++) {
        printf("Nome: %s\n", funcionario[j].nome);
        printf("Data de Nascimento: %s\n", funcionario[j].nasc);
        printf("Cidade Natal: %s\n", funcionario[j].cidade);
        printf("Idade: %d anos\n", funcionario[j].idade);
        printf("Senha: %s\n\n", funcionario[j].senha);
    }

    return 0;
}

