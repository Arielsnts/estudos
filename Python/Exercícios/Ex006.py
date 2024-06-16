cont1 = soma = cont = menor = 0
barato = ''
print('-' * 20)
print('LOJÃO'.center(20))
print('-' * 20)
while True:
    nome = str(input('Qual o nome do produto: '))
    valor = float(input('Qual o valor do produto: R$ '))
    cont1 += 1
    esc = str(input('Quer continuar? [S/N]: ')).upper()[0]
    soma += valor
    print('-' * 20)
    if valor > 1000:
        cont += 1
    if cont1 == 1 or valor < menor:
        menor = valor
        barato = nome
    if esc == 'N':
        break
print(f'A soma do valor de todos os produtos é {soma} R$.')
print(f'{cont} produtos ultrapassaram o valor de 1000 R$.')
print(f'O produto mais barato custa {menor} R$, e foi o {barato}.')
