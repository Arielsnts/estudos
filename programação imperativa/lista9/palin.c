#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parenteses(char arr[]) {
    int len = strlen(arr);

    int aberto = 0;
    int cont_paren = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] == '(' && aberto != -1) {
            aberto = 1;
            cont_paren++;
        }
        else if (arr[i] == ')' && aberto) {
            cont_paren--;
            if (cont_paren == 0) aberto = 0;
        }
        else if (arr[i] == ')' && !aberto) aberto = -1;
    }

    return aberto;
}

char* elimina_paren(char arr[]) {
    int len = strlen(arr);

    char *saida = (char*)malloc((len+1) * sizeof(char));
    int saida_len = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] != '(' && arr[i] != ')') {
            saida[saida_len] = arr[i];
            saida_len++;
        }
    }

    saida[saida_len] = '\0';

    saida = (char*)realloc(saida, saida_len * sizeof(char));

    return saida;
}

int palindromo(char arr[]) {
    int len = strlen(arr);

    int cont = 0;

    int i = 0, j = len - 1;

    while (i < j) {
        if (arr[i] != arr[j]) return 0;
        i++;
        j--;
    }

    return 1;
}

int main() {
    char entrada[1000];

    while (1) {
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            break;  
        }
        entrada[strcspn(entrada, "\n")] = '\0';
        
        if (entrada[0] == '\0') break;

        int aberto = parenteses(entrada);
        int palin = palindromo(elimina_paren(entrada));

        printf("----\n");
        if (aberto) printf("PARENTESES: NAO BALANCEADOS\n");
        else if (!aberto) printf("PARENTESES: BALANCEADOS\n");
        if (palin) printf("PALINDROMO: SIM\n");
        else if (!palin) printf("PALINDROMO: NAO\n");
    }
        printf("----\n");

    return 0;
}