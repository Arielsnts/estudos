from random import choice
from time import sleep
cont = cont2 = cont3 = 0
print('PEDRA-PAPEL-TESOURA\nDigite "encerrar" para fechar o jogo.')
while True:
    esc = input('Escolha uma opção: ').strip().upper()
    lista = ['PEDRA', 'PAPEL', 'TESOURA']
    maq = choice(lista)
    if esc == 'ENCERRAR':
        print(f'Venceu: {cont} vezes\nEmpatou {cont2} vezes\nPerdeu {cont3} vezes')
        print('Encerrando o jogo...')
        sleep(1)
        break
    print('Pedra...')
    sleep(1)
    print('Papel...')
    sleep(1)
    print('TESOURA!')
    sleep(1)
    print(f'Você escolheu {esc} e eu escolhi {maq}, então...')
    sleep(1)
    if maq == esc:
        print('\033[33mEMPATAMOS\033[m!')
        cont2 += 1
    elif maq == 'PEDRA' and esc == 'PAPEL':
        print('\033[32mVOCÊ GANHOU\033[m!')
        cont += 1
    elif maq == 'PAPEL' and esc == 'TESOURA':
        print('\033[32mVOCÊ GANHOU\033[m!')
        cont += 1
    elif maq == 'TESOURA' and esc == 'PEDRA':
        print('\033[32mVOCÊ GANHOU\033[m!')
        cont += 1
    else:
        print('\033[31mVOCÊ PERDEU\033[m!')
        cont3 += 1
