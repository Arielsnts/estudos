def area(comprimento, largura):
    return comprimento * largura

def perimetro(comprimento, largura):
    return 2 * (comprimento + largura)

comprimento = float(input('Digite o comprimento: '))
largura = float(input('Digite a largura: '))

a = area(comprimento, largura)
p = perimetro(comprimento, largura)
print(f'A área é: {a}\nO perímetro é: {p}')
