info = {}
gols = []
total = []
print('-=' * 15)
print('CADASTRO'.center(30))
print('-=' * 15) 
while True:
    info.clear()
    info['Nome'] = str(input('Digite o nome do jogador: '))
    partidas = int(input('Quantas partidas ele jogou? '))
    for p in range(1, partidas + 1):
        gols.append(int(input(f'  Quantos gols ele fez na {p} partida? ')))
    info['Gols'] = gols[:]
    info['Total de Gols'] = sum(gols)
    gols.clear()
    total.append(info.copy())
    while True:
        esc = str(input('Deseja continuar? [S/N] ')).strip().upper()[0]
        if esc in 'SN':
            break
        print('Digite "S" ou "N".', end=' ')
    if esc in 'Nn':
        break
    print('-=' * 30)
print('-=' * 30)
print('Jogador', end='')
for i in info.keys():
    print(f'      {i:<12}', end='')
print()
for k, v in enumerate(total):
    print(f'Jogador {k + 1} ', end='')
    for d in v.values():
        print(f'   {str(d):<15}', end='')
    print()
print('-=' * 30)
while True:
    busca = int(input('Digite o número do jogador (999 para parar): '))
    if busca == 999:
        break
    if busca >= len(total) + 1:
        print('Dado incorreto.')
    else:
        print(f'O jogador {total[busca-1]['Nome']} fez:')
        for i, g in enumerate(total[busca-1]['Gols']):
            print(f'No jogo {i+1}, fez {g} gols.')
    print('-=' * 30)
print('-=' * 30)
print('Encerrando...')
