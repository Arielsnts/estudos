from random import randint

print('JOGO DA ADVINHAÇÃO!')
num = int(input('Digite um número inteiro de 1 a 100: '))
sort = randint(1, 100)
cont = 1
while num != sort:
    if num < sort:
        print('Errou. O número é maior!')
    elif num > sort:
        print('Errou. O número é menor!')
    num = int(input('Digite outro número: '))
    cont += 1
print(f'ACERTOU em {cont} TENTATIVAS! O número era {sort}!')
