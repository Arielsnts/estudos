from math import factorial

num = int(input('Digite um número inteiro: '))
c = num
print(f'{num}! =', end=' ')
while True:
    print(f'{c}', end=' ')
    print(' x ' if c > 1 else ' = ', end=' ')
    c -= 1
    if c == 1:
        break
print(f'1 = {factorial(num)}')
