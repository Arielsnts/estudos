def fatorial(num=1, s=False):
    if s == False:
        f = 1
        for c in range(num, 0, -1):
             f *= c
        print(f'O fatorial de {num} é {f}.')
    if s == True:
        f = 1
        for c in range(num, 0, -1):
             f *= c
        print(f'{num}! =', end=' ')
        while True:
            print(f'{num}', end=' ')
            print(' x ' if num > 1 else ' = ', end=' ')
            num -= 1
            if num == 1:
                break
        print(f'1 = {f}')
            

fact = int(input('Digite um número inteiro: '))
esc = str(input(f'Quer ver o cálculo [S/N]? '))[0]
if esc in 'Ss':
    show = True
if esc in 'Nn':
    show = False
fatorial(num=fact, s=show)
