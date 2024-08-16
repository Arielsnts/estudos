frase = str(input('Digite uma frase: ')).strip().upper()
palavras = frase.split()
junto = ''.join(palavras)
inverso = ''
for c in range(len(junto) - 1, - 1, -1):
    inverso += junto[c]
print(f'Sua frase ao contrário é {inverso}.')
if inverso == junto:
    print('Essa frase é um palíndromo.')
else:
    print('Sua frase não é um palíndromo')
