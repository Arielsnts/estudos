from random import randint
from time import sleep

def sort(lista):
    print('Os valores sorteados foram: ', end='')
    for c in range(0, 5):
        n = randint(1, 10)
        lista.append(n)
        print(f'{n}', end=' ', flush=True)
        sleep(0.5)
    print('FIM!')

def somar(lista):
    soma = 0
    for v in lista:
        if v % 2 == 0:
            soma += v
    print(f'A soma dos valores pares é: {soma}')

num = []
sort(num)
somar(num)
