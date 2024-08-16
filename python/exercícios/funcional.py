def media(f, n1, n2, n3, p1=1, p2=1, p3=1): return f(n1, n2, n3, p1, p2, p3)

def situacao(carga, faltas, media):
    if media < 5:
        return "reprovado"
    elif carga == 4 and faltas > 15:
        return "reprovado"
    elif carga == 4 and faltas >= 8 and media < 7:
        return "reprovado"
    elif carga == 6 and faltas > 22:
        return "reprovado"
    elif carga == 6 and faltas >= 11 and media < 7:
        return "reprovado"
    elif carga == 2 and faltas > 7:
        return "reprovado"
    elif carga == 2 and faltas >= 3 and media < 7:
        return "reprovado"
    else:
        return "aprovado"


n1 = float(input('Digite sua primeira nota: '))
n2 = float(input('Digite sua segunda nota: '))
n3 = float(input('Digite sua terceira nota: '))

ponderada = str(input('A média precisa de peso? [S/N] ')).upper()[0]
if ponderada == "S":
    p1 = float(input('Digite seu primeiro peso: '))
    p2 = float(input('Digite seu segundo peso: '))
    p3 = float(input('Digite seu terceiro peso: '))

carga = int(input('Digite o número de créditos da disciplina: '))
faltas = int(input('Digite o número de faltas: '))

print(situacao(carga, faltas,
                media(lambda n1, n2, n3, p1, p2, p3: (n1*p1 + n2*p2 + n3*p3)/ (p1 + p2 + p3),
                       n1, n2, n3, p1, p2, p3)))
