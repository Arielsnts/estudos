#include <stdio.h>

int main() {
    int n1, n2;

    scanf("%d%*c%d", &n1, &n2);

    for (int i = n1; i <= n2; i++) {
        printf("%d\n", i);
    }

    return 0;
}
