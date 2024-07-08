def nota(*n, sit=False):
    d = {}
    d['Total'] = len(n)
    d['Maior'] = max(n)
    d['Menor'] = min(n)
    d['Média'] = sum(n)/len(n)
    if sit == True:
        if d['Média'] >= 7:
            d['Situação'] = 'Boa'
        if d['Média'] >= 5 and d['Média'] <= 6.9:
            d['Situação'] = 'Razoável'
        else:
            d['Situação'] = 'Ruim'
    return d


resp = nota(5, 6, 7, 8, sit=True)
print(resp)
