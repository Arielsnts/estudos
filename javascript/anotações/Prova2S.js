const processarStringPacientes = (input) => {
    const listaA = input.match(/O imc de [A-Za-z]+ é \d+(\.\d+)?/g)
    const listaB = listaA.map(str => {
        const [, nome, imc] = str.match(/O imc de (\w+) é (\d+(\.\d+)?)/)
        return {nome, imc: parseFloat(imc)}
    })
    return listaB
}

const inputStr = "O imc de Fred é 25.3. O imc de Maria é 20.2. O imc de Ana é 15.5. O imc de Paulo é 32.4"
const pacientesProcessados = processarStringPacientes(inputStr) // lista dos pacientes processados

const inputLista = Object.freeze([
    { nome: 'Fred', imc: 25.3 },
    { nome: 'Maria', imc: 20.2 },
    { nome: 'Ana', imc: 15.5 },
    { nome: 'Paulo', imc: 32.4 }
    ])

const ordenarPacientePorIMC = (input) => {
    const listaCopia = [...input]
    return listaCopia.sort((a, b) => a.imc - b.imc)
}

const maiorEmenorPacientes = (input) => {
    const listaCopia = [...input]
    const ordem = ordenarPacientePorIMC(listaCopia)
    return {menor: ordem[0].nome, maior: ordem[ordem.length - 1].nome}
}

const classificarPacientes = (input) => {
    return input.map(paciente => ({
      ...paciente,
      risco: paciente.imc < 18.5 
        ? 'Baixo Peso'
        : paciente.imc < 24.9 
        ? 'Peso Normal'
        : paciente.imc < 29.9 
        ? 'Sobrepeso'
        : 'Obesidade'
    }))
}

// questão 1
console.log(pacientesProcessados)
// questão 2
console.log(ordenarPacientePorIMC(inputLista))
// questão 3
console.log(maiorEmenorPacientes(inputLista))
// questão 4
console.log(classificarPacientes(inputLista))
// teste final
console.log(inputLista)