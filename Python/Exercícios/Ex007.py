total = 0
cont = 0
cont1 = 0
maior = 0
nhomem = 0
for a in range(1, 4):
    print(f'Pessoa número {a}:')
    nome = input('Digite o nome: ')
    idade = int(input('Digite a idade: '))
    gen = input('Digite o gênero (M/F): ')
    if idade > 0:
        total += idade
        cont += 1
    if a == 1 and gen in 'Mm':
        maior = idade
        nhomem = nome
    else:
        if idade > maior and gen in 'Mm':
            maior = idade
            nhomem = nome
    if gen in 'Ff' and idade < 20:
        cont1 += 1
print(f'A média de idade do grupo é {total / cont:.1f}.')
print(f'A maior idade dentre os homens é a do {nhomem}, de {maior} anos.')
print(f'O número de mulheres com menos de 20 é {cont1}.')
