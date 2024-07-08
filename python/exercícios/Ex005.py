print('Menu de operações.')
num1 = int(input('Digite um número inteiro: '))
num2 = int(input('Digite outro número inteiro: '))
while True:
    print('Opções:')
    print('[ 1 ] - Somar os valores\n[ 2 ] - Multiplicar os valores\n[ 3 ] - Maior')
    print('[ 4 ] - Novos números\n[ 5 ] - Fechar o programa')
    esc = str(input('Escolha uma opção: '))
    if esc == '1':
        print(f'>>>> A soma entre {num1} e {num2} é {num1 + num2}.')
    if esc == '2':
        print(f'>>>> A multiplicação entre {num1} e {num2} é {num1 * num2}.')
    if esc == '3':
        if num1 > num2:
            print(f'>>>> {num1} é o número maior.')
        if num1 < num2:
            print(f'>>>> {num2} é o número maior.')
        if num1 == num2:
            print('>>>> Os dois valores são iguais')
    if esc == '4':
        num1 = int(input('Digite um número inteiro: '))
        num2 = int(input('Digite outro número inteiro: '))
    print('-==-' * 10)
    if esc == '5':
        print('Fechando o programa...')
        break
