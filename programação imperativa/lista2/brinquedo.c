#include <stdio.h>

int main() {
    int altura, idade;
    
    scanf("%d %d", &altura, &idade);

    int viking = 0;
    int death = 0;
    int killer = 0;

    if (altura >= 150 && idade >= 12) viking = 1;
    if (altura >= 140 && idade >= 14) death = 1;
    if (altura >= 170 || idade >= 16) killer = 1;

    int total = viking + death + killer;

    printf("%d\n", total);

    return 0;
}