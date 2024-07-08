print('-' * 20)
print('BANCO ARIEL'.center(20))
print('-' * 20)
num = float(input('Digite o valor a ser sacado: R$ '))
valor = num
ced = 100
cont = 0
while True:
    if valor >= ced:
        valor -= ced
        cont += 1
    else:
        if cont > 0:
            print(f'{cont} cédula (s) de {ced}')
        if ced == 100:
            ced = 50
        elif ced == 50:
            ced = 20
        elif ced == 20:
            ced = 10
        elif ced == 10:
            ced = 5
        elif ced == 5:
            ced = 2
        elif ced == 2:
            ced = 1
        cont = 0
        if valor == 0:
            break
