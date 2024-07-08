maior = menor = 0
dados = []
tot = []
while True:
    dados.append(str(input('Digite um nome: ')))
    dados.append(int(input('Digite um peso: ')))
    if len(tot) == 0:
        maior = menor = dados[1]
    else:
        if dados[1] > maior:
            maior = dados[1]
        elif dados[1] < menor:
            menor = dados[1]
    tot.append(dados[:])
    dados.clear()
    esc = str(input('Quer continuar? [S/N] ')).upper()[0]
    if esc == 'N':
        break
print(f'O número de pessoas cadastradas foi {len(tot)}')
print(f'O menor peso foi {menor} de ', end='')
for p in tot:
    if p[1] == menor:
        print(p[0])
print(f'O maior peso foi {maior} de ', end='')
for pm in tot:
    if pm[1] == maior:
        print(pm[0])
