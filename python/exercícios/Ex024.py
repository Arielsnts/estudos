from datetime import datetime
ano = datetime.now().year
info = {}
info['Nome'] = str(input('Digite seu nome: '))
info['Ano de Nascimento'] = int(input('Digite seu ano de nascimento: '))
info['Carteira'] = int(input('Digite sua carteira de trabalho [0 caso não tenha]: '))
info['Idade'] = ano - info['Ano de Nascimento']
if info['Carteira'] > 0:
    info['Ano de Contratação'] = int(input('Digite o ano de contratação: '))
    info['Sálario'] = float(input('Digite seu sálario: R$ '))
    info['Aposentadoria'] = 70 - info['Idade']
print('-=' * 30)
print(f'Seu nome é {info['Nome']}')
print(f'Sua idade é {info['Idade']}')
if info['Carteira'] > 0:
    print(f'Você foi contratado com {info["Ano de Contratação"] - info["Ano de Nascimento"]} anos.')
    print(f'Você vai se aposentar daqui a {info["Aposentadoria"]} anos')
    print(f'Seu sálario é de R$ {info['Sálario']}')
