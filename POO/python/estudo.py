num = int(input("Digite um número inteiro: "))

ultimo = 0
soma = 0

while num != 0:
    ultimo = num % 10

    fat = 1
    for i in range(1, ultimo+1):
        fat *= i
    
    soma += fat
    num //= 10

print("Saída:", soma)
