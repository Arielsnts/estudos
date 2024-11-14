const inputStr = "O João tem 78 anos. A Maria tem 30 anos. O Carlos tem 15 anos. A Fernanda tem 10 anos. O Pedro tem 35 anos. A Luísa tem 20 anos. "

const processarNomes = (input) => {
    const listaA = input.match(/[AO] [A-Za-zãÃáÁõÕ]+ tem \d+ anos/g)
    const listaB = listaA.map(str => {
        const [, nome, idade] = str.match(/[AO] ([A-Za-zãÃáÁõÕ]+) tem (\d+) anos/)
        return {nome, idade: parseInt(idade)}
    })
    return listaB
}

const listaPrincipal = processarNomes(inputStr)

const maiorDeIdade = (lista) => {
    const listaC = [...lista]
    return listaC.filter(x => x.idade >= 18)
}

const maiorEmenor = (lista) => {
    const ordem = [...lista].sort((a, b) => a.idade - b.idade)
    return {menor: ordem[0].nome, maior: ordem[ordem.length - 1].nome
    }
}

const faixaEtaria = (lista) => {
    return lista.map(pessoa => ({
        ...pessoa,
        faixa_etaria: pessoa.idade < 12
        ? "criança"
        : pessoa.idade < 18
        ? "adolescente"
        : pessoa.idade < 60
        ? "adulto"
        : "idoso"
    }))
}

const mediaIdade = (lista) => {
    const listaC = [...lista]
    return parseFloat((listaC.reduce((acc, x) => acc + x.idade, 0) / listaC.length).toFixed(1))
}

console.log(maiorDeIdade(listaPrincipal))
console.log(maiorEmenor(listaPrincipal))
console.log(faixaEtaria(listaPrincipal))
console.log(mediaIdade(listaPrincipal))
console.log(listaPrincipal)