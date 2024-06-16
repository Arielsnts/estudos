valor = list()
for v in range(0, 5):
    valor.append(int(input('Digite um valor: ')))
print(f'Os números digitados foram {valor}')
print(f'O maior valor foi {max(valor)} na posição:', end=' ')
for i, v in enumerate(valor):
    if v == max(valor):
        print(i)
print(f'O menor valor foi {min(valor)} na posição:', end=' ')
for i, v in enumerate(valor):
    if v == min(valor):
        print(i)
