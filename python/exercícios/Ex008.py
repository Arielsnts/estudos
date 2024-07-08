n1 = int(input('Digite um número: '))
cont = 0
for i in range(1, n1 + 1):
    if n1 % i == 0:
        print(f'\033[32m{i}\033[m', end=' ')
        cont = cont + 1
    else:
        print(f'\033[31m{i}\033[m', end=' ')
print(f'\nDivisível {cont} vezes.', end=' ')
if cont == 2:
    print('É um número primo.')
else:
    print('Não é um número primo.')
