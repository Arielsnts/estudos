cont = soma = maior = menor = 0
while True:
    num = int(input('Digite um número inteiro: '))
    cont += 1
    soma += num
    if  cont == 1:
        maior = menor = num
    else:
        if num > maior:
            maior = num
        if num < menor:
            menor = num
    resp = input('Deseja continuar? [S/N] ').upper()[0]
    if resp == 'N':
        break
print(f'O maior número é {maior} e o menor é {menor}')
print(f'A média entre os números é {soma / cont:.1f}')
