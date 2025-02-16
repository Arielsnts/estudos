#include <stdio.h>

int main() {
    int n = -1;

    char palavra[50][100000];
    int numChar[50];

    int index = 0;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        numChar[index] = n;

        scanf("%s", &palavra[index][0]);

        index++;
    }

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < numChar[i]/2; j++) {
            char temp;
            temp = palavra[i][j];
            palavra[i][j] = palavra[i][numChar[i]-j-1];
            palavra[i][numChar[i]-j-1] = temp;
        }
    }
    
    for (int i = 0; i < index; i++) {
        printf("%s\n", palavra[i]);
    }

    return 0;
}
