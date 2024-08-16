def contador(i, f, p):
    print('-=' * 30)
    print(f'A sequência que começa com {i}, termina com {f}, com passo de {p}, é:')
    if p < 0:
        p *= -1
    if p == 0:
        p = 1
    if i > f:
        cont = i
        while cont >= f:
            print(f'{cont}', end=' ')
            cont -= p
    if i < f:
        cont = i
        while cont <= f:
            print(f'{cont}', end=' ')
            cont += p
    print()

contador(1, 10, 1)
contador(20, 1, 2)
print('-=' * 30)
ini = int(input('Escolha seu ínicio: '))
fim = int(input('Escolha seu fim:    '))
pas = int(input('Escolha seu passo:  '))
contador(i=ini, f=fim, p=pas)
