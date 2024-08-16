def leia(num):
    ok = False
    valor = 0
    while True:
        n = str(input(num)).strip()
        if n.isnumeric():
            valor = int(n)
            ok = True
        else:
            print('ERRO! Digite um número inteiro')
        if ok == True:
            break
    return valor    


n = leia('Digite um número inteiro: ')
print(f'Você digitou o número {n}')
