def ficha(n=0, g=0):
    if g.isnumeric():
        g = int(g)
    else:
        g = 0
    if n != '' and g != '':
        print(f'O jogador {n} fez {g} gols.')
    if n == '' and g == '':
        n = '<desconhecido>'
        g = 0
        print(f'O jogador {n} fez {g} gols.')
    if n != '' and g == '':
        g = 0
        print(f'O jogador {n} fez {g} gols.')
    if n == '' and g != '':
        n = '<desconhecido>'
        print(f'O jogador {n} fez {g} gols.')

nome = str(input('Digite o nome do jogador: '))
gols = str(input('Digite a quantidade de gols: '))
ficha(n=nome, g=gols)
