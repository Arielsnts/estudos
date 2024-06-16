situation = {}
situation['Nome'] = str(input('Digite o nome do aluno: '))
situation['Média'] = int(input('Digite a média do aluno: '))
if situation['Média'] > 7:
    situation['Situação'] = 'Aprovado'
elif situation['Média'] > 5 and situation['Média'] <= 6.9:
    situation['Situação'] = 'Recuperação'
else:
    situation['Situação'] = 'Reprovado'
for k, v in situation.items():
    print(f'{k} = {v}')
