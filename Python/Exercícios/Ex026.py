from time import sleep
print('-=' * 15)
print('CADASTRO'.center(30))
print('-=' * 15)
biblioteca = {}
lista = []
cont = soma = 0
while True:
    biblioteca['nome'] = str(input('Digite um nome: ')).strip()
    cont += 1
    biblioteca['idade'] = int(input('Digite a idade: ').strip())
    soma += biblioteca['idade']
    while True:
        biblioteca['sexo'] = str(input('Digite seu sexo [M/F]: ')).strip()[0]
        if biblioteca['sexo'] in 'MFmf':
            break
        print('Digite "M" ou "F".', end=' ')
    lista.append(biblioteca.copy())
    while True:
        esc = str(input('Deseja continuar? [S/N] ')).strip().upper()[0]
        if esc in 'SN':
            break
        print('Digite "S" ou "N".', end=' ')
    if esc in 'Nn':
        break
    print('-=' * 15)
media = soma / cont
print('-=' * 15)
print('INFORMAÇÕES'.center(30))
print('-=' * 15)
sleep(1)
print(f'>>> O número de pessoas cadastradas é {cont}')
sleep(2)
print(f'>>> A média de idade dos cadastrados é {media:.1f}')
sleep(2)
print(f'>>> As cadastradas do sexo feminino são:')
for p in lista:
    if p['sexo'] in 'fF':
        print(f'{p["nome"]} |', end=' ', flush=True)
        sleep(1)
print('\n>>> As pessoas com idade acima ou igual a média são:')
for p in lista:
    if p['idade'] >= media:
        for k, v in p.items():
                print(f'{k} = {v} |', end=' ', flush=True)
                sleep(1)
print('\n>>> Encerrando...')
sleep(2)
