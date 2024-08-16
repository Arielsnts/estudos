def existe(nome):
    try:
        a = open(nome, 'rt')
        a.close()
    except FileNotFoundError:
        return False
    else:
        return True
    
def crie(nome):
    a = open(nome, 'wt+')
    a.close()

def leia(nome):
    try:
        a = open(nome, 'rt')
    except:
        print('ERRO ao ler cadastrados!')
    else:
        for l in a:
            dado = l.split(';')
            dado[1] = dado[1].replace('\n', '')
            print(f'{dado[0]:<30}{dado[1]:>3} anos')

def cad(arq, nome='Desconhecido', idade=0):
    try:
        a = open(arq, 'at')
    except:
        print('ERRO ao tentar cadastrar!')
    else:
        try:
            a.write(f'{nome};{idade}\n')
        except:
            print('ERRO ao fazer cadastro!')
        else:
            print(f'Novo cadastro de {nome}!')
            a.close()
