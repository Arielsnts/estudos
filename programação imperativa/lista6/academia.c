#include <stdio.h>
#include <string.h>

int main() {
    char nomes[100][51];
    int senha[100];
    char mensalidade[100];

    int clientes = 0;
    while (1) {
        char temp[51];

        gets(temp);

        if (strcmp(temp, "SAIR") == 0) break;

        strcpy(nomes[clientes], temp);

        scanf("%d", &senha[clientes]);

        scanf(" %c%*c", &mensalidade[clientes]);

        clientes++;
    }

    int entrada[100];
    int quantSenhas = 0;
    
    while (1) {
        int temp;
        scanf("%d", &temp);

        if (temp == -1) break;

        entrada[quantSenhas] = temp;
        quantSenhas++;
    }

    int iEntrada = 0, iSenha = 0, cont = 0;

    while (iEntrada < quantSenhas) {
        cont = 0;
        for (iSenha; iSenha < clientes; iSenha++) {
            if (entrada[iEntrada] == senha[iSenha]) {
                cont = 1;
                if (mensalidade[iSenha] == 'P') {
                    printf("%s, seja bem-vindo(a)!\n", nomes[iSenha]);
                }
                else if (mensalidade[iSenha] == 'F') {
                    printf("Não está esquecendo de algo, %s? Procure a recepção!\n", nomes[iSenha]);
                }
                break;
            }
        }

        if (cont == 0) printf("Seja bem-vindo(a)! Procure a recepção!\n");

        iSenha = 0;
        iEntrada++;
    }
    
    return 0;
}