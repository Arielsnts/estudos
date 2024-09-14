function processarStringPacientes(string) {
    const listaA = string.match(/O imc de [A-Za-z]+ é \d+(\.\d+)?/g)
    const listaB = listaA.map(str => {
        const [, nome, imc] = str.match(/O imc de (\w+) é (\d+(\.\d+)?)/)
        return {nome, imc: parseFloat(imc)}
    })
    return listaB
}

const inputStr = "O imc de Fred é 25.3. O imc de Maria é 20.2. O imc de Ana é 15.5. O imc de Paulo é 32.4"
const pacientesProcessados = Object.freeze(processarStringPacientes(inputStr))

const ordenarPacientePorIMC = (registro) => {
    return [...registro].sort((a, b) => a.imc - b.imc)
}

const maiorEmenorPacientes = (registro) => {
    const ordem = ordenarPacientePorIMC(registro)
    return {menor: ordem[0].nome, maior: ordem[ordem.length - 1].nome}
}

const classificarPacientes = (registro) => {
    return registro.map(paciente => ({
        ...paciente,
        risco: paciente.imc < 18.5
        ? "abaixo do peso"
        : paciente.imc < 24.9
        ? "peso normal"
        : paciente.imc < 29.9
        ? "sobrepeso"
        :"obesidade"
    }))
}

const calcularMediaIMC = (registro) => {
    const lista = [...registro]
    return parseFloat((lista.reduce((acc, x) => acc + x.imc, 0) / lista.length).toFixed(1))
}

// questão 1
console.log(processarStringPacientes(inputStr))
// questão 2
console.log(ordenarPacientePorIMC(pacientesProcessados))
// questão 3
console.log(maiorEmenorPacientes(pacientesProcessados))
// questão 4
console.log(classificarPacientes(pacientesProcessados))
// questão 5
console.log(calcularMediaIMC(pacientesProcessados))
// teste final
console.log(pacientesProcessados)