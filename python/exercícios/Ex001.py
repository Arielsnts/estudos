from random import randint

cont = 0
while True:
    esc = str(input('ÍMPAR ou PAR? [I/P]: ')).upper()[0]
    num = int(input('Digite um número inteiro de 1 a 10: '))
    maq = randint(1, 10)
    soma = num + maq
    if soma % 2 == 0 and esc == 'P' or soma % 2 == 1 and esc == 'I':
        print(f'Você escolheu {num} e eu escolhi {maq}, que resulta em {soma}. VOCÊ GANHOU!')
        cont += 1
    if soma % 2 == 1 and esc == 'P' or soma % 2 == 0 and esc == 'I':
        print(f'Você escolheu {num} e eu escolhi {maq}, que resulta em {soma}. VOCÊ PERDEU!')
        break
print(f'O número de vitórias seguidas foi {cont}!')
