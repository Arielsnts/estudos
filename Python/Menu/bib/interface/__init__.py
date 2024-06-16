def linha(txt):
    print('-' * 60)
    print(f'{txt}'.center(60))
    print('-' * 60)

def ler(txt):
    ok = False
    valor = 0
    while True:
        n = str(input(txt)).strip()
        if n.isalpha() or n == '':
            print('ERRO! Digite um número.')
        else:
            valor = int(n)
            ok = True
        if ok == True:
            break
    return valor

def options(txt):
    print('Opção 1 - MOSTRAR CADASTRADOS\nOpção 2 - CADASTRAR\nOpção 3 - FECHAR SISTEMA')
    print('-' * 60)
    while True:
        e = ler(txt)
        if e > 3 or e < 1:
            print('ERRO! Digite um número dentre as opções.')
        else:
            break
    return e
