print('-=' * 30)
print('BOLETIM ESCOLAR'.center(30))
print('-=' * 30)
lista = []
while True:
    nome = (str(input('Digite um nome: ')))
    nota1 = int(input('Digite a primeira nota: '))    
    nota2 = int(input('Digite a segunda nota: '))
    media = (nota1 + nota2) / 2
    lista.append([nome, [nota1, nota2], media])
    esc = str(input('Deseja continuar? [S/N] ')).upper()[0]
    if esc == 'N':
        break
print('-=' * 30)
for i, l in enumerate(lista):
    print(f'Aluno {i + 1} - {l[0]} - média {l[2]}')
print('-=' * 30)
while True:
    esc = int(input('Digite o número do aluno escolhido [999 para encerrar]: '))
    if esc == 999:
        print('Encerrando')
        break
    if esc <= len(lista):
        print(f'O aluno {lista[esc - 1][0]} ficou com as notas {lista[esc - 1][1]}')
        print('-=' * 30)
