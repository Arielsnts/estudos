#include <stdio.h>
#include <string.h>

int main() {
    char string[100001];

    fgets(string, 100001, stdin);

    int len = strlen(string);
    int ponto = 0;

    for (int i = 0; i < len; i++) {
        if (i == 0) {
            if (string[i] == '4') string[i] = 'A';
            else if (string[i] == '5') string[i] = 'E';
            else if (string[i] == '1') string[i] = 'I';
            else if (string[i] == '0') string[i] = 'O';
            else if (string[i] == '2') string[i] = 'U';
        }
        else if (string[i] == '.' && string[i+1] == ' ') {
            ponto = 1;
        }
        else if (ponto) {
            if (string[i] == '4') string[i] = 'A', ponto = 0;
            else if (string[i] == '5') string[i] = 'E', ponto = 0;
            else if (string[i] == '1') string[i] = 'I', ponto = 0;
            else if (string[i] == '0') string[i] = 'O', ponto = 0;
            else if (string[i] == '2') string[i] = 'U', ponto = 0;
        }
        else {
            if (string[i] == '4') string[i] = 'a';
            else if (string[i] == '5') string[i] = 'e';
            else if (string[i] == '1') string[i] = 'i';
            else if (string[i] == '0') string[i] = 'o';
            else if (string[i] == '2') string[i] = 'u';
        }
    }

    printf("%s", string);

    return 0;
}