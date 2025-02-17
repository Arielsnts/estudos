#include <stdio.h>

int main() {
    int n;
    char palavra[100001];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        scanf("%s", palavra);

        for (int i = 0, j = n - 1; i < j; i++, j--) {
            char temp = palavra[i];
            palavra[i] = palavra[j];
            palavra[j] = temp;
        }

        printf("%s\n", palavra);
    }

    return 0;
}
