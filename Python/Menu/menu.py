from bib.interface import *
from bib.arquivo import *
from time import sleep

arq = 'cadastro.txt'

if not existe(arq):
    crie(arq)

while True:
    linha('MENU PRINCIPAL')
    esc = options('Digite sua opção: ')
    if esc == 1:
        linha('CADASTRADOS')
        leia(arq)
        sleep(3)
    if esc == 2:
        linha('CADASTRO')
        nome = str(input('Nome: '))
        idade = ler('Idade: ')
        cad(arq, nome, idade)
        sleep(3)
    if esc == 3:
        break
print('<<Encerrando o Sistema>>')
sleep(2)
