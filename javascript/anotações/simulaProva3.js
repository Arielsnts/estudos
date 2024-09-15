const inputLista = "banana, maçã, laranja, abacaxi"
const inputLista2 = "1,2,3,4,5,6,7,8,9,10"

function processarString(string) {
    return string.split(/,\s*/)
}

const imparPar = (lista) => {
    const listaA = [...lista]
    const teste = listaA.filter(x => isNaN(x))
    if (teste.length > 0)
        return "Não é uma lista de números!"
    return listaA.map(x => ({
        numero: x,
        par: x % 2 === 0
    }))
}

const alfaOrdenar = (lista) => {
    return [...lista].sort()
}

const maiorEmenor = (lista) => {
    const listaA = [...lista].sort((a, b) => a - b)
    return {menor: listaA[0], maior: listaA[listaA.length - 1]}
}

const comprimentoPalavras = (lista) => {
    const listaA = [...lista]
    return listaA.map(x => ({
        palavra: x,
        comprimento: x.length < 4
        ? "curta"
        : x.length < 7
        ? "média"
        : "longa"
    }))
}

const mediaEsoma = (lista) => {
    const listaA = [...lista]
    const soma = listaA.reduce((acc, x) => acc + x)
    const media = soma / listaA.length
    return {soma, media}
}

const strings = processarString(inputLista)
const numeros = processarString(inputLista2)

// testes
console.log(imparPar(numeros))
console.log(comprimentoPalavras(strings))
