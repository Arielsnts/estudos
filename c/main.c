#include <stdio.h>

#define titulo "-- Linguagem C --"

int main() {
    printf("%s\n", titulo);

    int valor = 0;
    printf("Digite um número inteiro maior que zero: ");
    scanf("%d", &valor);

    int resultado = 1;
    for (int i = 1; i <= valor; i++) {
        resultado *= i;
    };
    
    printf("O fatorial de %d é igual a %d\n", valor, resultado);
}
