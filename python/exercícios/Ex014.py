lista = list()
while True:
    num = int(input('Digite um número: '))
    if num not in lista:
        lista.append(num)
    else:
        print('Número repetido.', end=' ')
    esc = input('Deseja continuar? [S/N] ').upper()[0]
    if esc == 'N':
        break
print(f'Os números escolhidos, em ordem crescente, são: {lista}')
