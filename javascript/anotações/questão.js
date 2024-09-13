const inputLista = Object.freeze([
    { nome: 'Fred', imc: 25.3 },
    { nome: 'Maria', imc: 20.2 },
    { nome: 'Ana', imc: 15.5 },
    { nome: 'Paulo', imc: 32.4 }
    ])
    if (listaCopia.imc < 18.5) condicao == "baixo peso"
    else if (listaCopia.imc >= 18.5 && listaCopia.imc < 24.9) condicao == "peso normal"
    else if (listaCopia.imc >= 24.9 && listaCopia.imc < 29.9) condicao == "sobrepeso"
    else condicao == "obesidade"
const ordenarPacientePorIMC = (input) => {
    const listaCopia = [...input]
    return listaCopia.sort()
}

console.log(ordenarPacientePorIMC(inputLista))
console.log(inputLista)