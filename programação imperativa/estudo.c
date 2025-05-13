#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("~Calculadora Inteira~\n");
    printf("-------------------\n");
    printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Sair\n");
    printf("-------------------\n");

    while (1)
    {
        int escolha = 0;
        int num1 = 0, num2 = 0;
        int resultado = 0;

        printf("\nDigite a opção: ");
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > 5) {
            printf("\n-----------------------\n");
            printf("ERRO! Digite novamente.\n");
            printf("-----------------------\n");
            continue;
        }
        else if (escolha == 5) break;

        printf("\nDigite o primeiro número: ");
        scanf("%d", &num1);
        printf("\nDigite o segundo número: ");
        scanf("%d", &num2);

        if (escolha == 1) resultado = num1 + num2;
        else if (escolha == 2) resultado = num1 - num2;
        else if (escolha == 3) resultado = num1 * num2;
        else if (escolha == 4) {
            if (num2 == 0) {
                printf("\n------------\n");
                printf("ERRO! Divisão por zero!\n");
                printf("------------\n");
                continue;
            }
            else resultado = num1 / num2;
        }

        printf("\n------------\n");
        printf("Resultado: %d\n", resultado);
        printf("------------\n");
    }
}