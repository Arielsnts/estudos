#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int hamburguer;
    int cheeseburguer;
    int fritas;
    int refrigerantes;
    int milkshake;

    scanf("%d", &hamburguer);
    scanf("%d", &cheeseburguer);
    scanf("%d", &fritas);
    scanf("%d", &refrigerantes);
    scanf("%d", &milkshake);

    float valorHamburguer = 3 * hamburguer;
    float valorCheeseburguer = 2.5 * cheeseburguer;
    float valorFritas = 2.5 * fritas;
    float valorRefrigerante = 1 * refrigerantes;
    float valorMilkshake = 3 * milkshake;

    float total = valorCheeseburguer + valorFritas + valorHamburguer + valorMilkshake + valorRefrigerante;

    printf("Conta final: %.2f\n", total);
	return 0;
}
