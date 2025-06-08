import math

def media(lista):
    soma = 0
    n = len(lista)
    for i in lista:
        soma += i
    return soma / n

def variancia(lista):
    Xmedia = media(lista)
    n = len(lista)

    soma = 0
    for i in lista:
        soma += pow(i - Xmedia, 2)
    
    return soma / (n-1)

def desvioPadrao(lista):
    var = variancia(lista)
    return math.sqrt(var)


entrada = []


n = int(input("Digite a quantidade de números: "))
for i in range(0, n):
    valor = float(input("Digite um número: "))
    entrada.append(valor)

print(f"Media: {media(entrada):.1f}\nVariancia: {variancia(entrada):.1f}\nDesvio: {desvioPadrao(entrada):.1f}")
