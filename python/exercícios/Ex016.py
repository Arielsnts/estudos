lista = list()
par = list()
impar = list()
while True:
    num = int(input('Digite um número: '))
    lista.append(num)
    esc = input('Deseja continuar? [S/N] ').upper()[0]
    if esc == 'N':
        break
for i, p in enumerate(lista):
    if p % 2 == 0:
        par.append(p)
    elif p % 2 == 1:
        impar.append(p)
print(f'Os números escolhidos foram {lista}')
print(f'Os pares foram {par}')
print(f'Os ímpares foram {impar}')
