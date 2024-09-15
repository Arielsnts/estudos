const lista1 = Object.freeze([1, 2, 3, 4, 5])
const lista2 = Object.freeze(['banana', 'maçã', 'laranja', 'abacaxi'])
const lista3 = Object.freeze([10, 5, 8, 3, 7])
const lista4 = Object.freeze(['sol', 'elefante', 'carro', 'mar'])
const lista5 = Object.freeze([10, 20, 30, 40])

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
// testes
console.log(imparPar(lista1))