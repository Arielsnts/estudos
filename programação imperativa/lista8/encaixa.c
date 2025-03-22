#include <stdio.h>

int encaixa(int a, int b)
{
    int tam_b = 0, bTemp = b;

    while (bTemp != 0) {
        bTemp /= 10;
        tam_b++;
    }

    bTemp = tam_b;
    
    for (int i = 0; i < tam_b; i++) {
        bTemp *= 10;
    }

    bTemp /= tam_b;
    a %= bTemp;

    if (a == b) return 1;
    else return 0;
}

int main(void) 
{
    int x, y;
    
    scanf("%d%d", &x, &y);
    while (x != -1) // lê enquanto x for diferente de -1
    {
        printf("%d\n", encaixa(x, y) );
        scanf("%d%d", &x, &y);
    }
	return 0;
}
