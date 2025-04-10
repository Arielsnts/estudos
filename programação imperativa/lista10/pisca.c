#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char *entrada = (char*)malloc(76 * sizeof(char));

    while (1) {
        fgets(entrada, 76, stdin);
        entrada[strcspn(entrada, "\n")] = '\0';
        
        if (strcmp(entrada, "the end!") == 0) break;

        for (int i = 0; entrada[i] != '\0'; i++) {
            entrada[i] = toupper(entrada[i]);
        }
        printf("%s", entrada);
    }

    return 0;
}