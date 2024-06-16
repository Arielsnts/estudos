from random import randint
quant = int(input('Digite a quantidade de jogos: '))
lista = []
jogo = []
numjogo = 1
while numjogo <= quant:
    cont = 0
    while True:
        num = randint(1, 60)
        if num not in lista:
            lista.append(num)
            cont += 1
        if cont == 6:
            break
    lista.sort()
    jogo.append(lista[:])
    lista.clear() 
    numjogo += 1
for i, l in enumerate(jogo):
    print(f'jogo {i + 1}: {l}')
