from operator import itemgetter
from random import randint
from time import sleep
jogo = {'Jogador 1': randint(1, 6),
        'Jogador 2': randint(1, 6),
        'Jogador 3': randint(1, 6),
        'Jogador 4': randint(1, 6)}
ranking = []
for k, v in jogo.items():
    print(f'{k} = {v}')
    sleep(1)
ranking = sorted(jogo.items(), key=itemgetter(1), reverse=True)
print('A ordem ficou:')
for i, v in enumerate(ranking):
    print(f'Jogador {i + 1} com o número {v[1]}.')
    sleep(1)
