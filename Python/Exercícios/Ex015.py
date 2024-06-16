lista = list()
while True:
    num = int(input('Digite um número: '))
    lista.append(num)
    esc = input('Deseja continuar? [S/N] ').upper()[0]
    if esc == 'N':
        break
print(f'A quantidade de números digitados foi {len(lista)}')
lista.sort(reverse=True)
print(f'A lista, em ordem decrescente, é {lista}')
if 5 in lista:
    print('O número 5 está na lista.')
else:
    print('O número 5 não está na lista.')
