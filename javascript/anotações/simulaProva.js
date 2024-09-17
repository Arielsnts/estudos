const inputStr = "O imc de Fred é 25.3. O imc de Maria é 20.2. O imc de Ana é 15.5. O imc de Paulo é 32.4"

function processarPacientes(string) {
    const aLista = string.match(/O imc de [A-Za-z]+ é \d+(\.\d+)?/g)
    const bLista = aLista.map(str => {
        const [, nome, imc] = str.match(/O imc de (\w+) é (\d+(\.\d+)?)/)
        return {nome, imc: parseFloat(imc)}
    })
    return bLista
}

function ordenarPacientePorIMC(lista) {
    return [...lista].sort((a, b) => a.imc - b.imc)
}

function maiorEmenorPacientes(lista) {
    const ordem = ordenarPacientePorIMC(lista)
    return {menor: ordem[0].nome, maior: ordem[ordem.length - 1].nome}
}

function classificarPacientes(lista) {
    return lista.map(paciente => ({
        ...paciente,
        risco: paciente.imc < 18.5
        ? "abaixo"
        : paciente.imc < 24.9
        ? "normal"
        : paciente.imc < 29.9
        ? "acima"
        : "obesidade"
    }))
}

function calcularMediaIMC(lista) {
    const copia = [...lista]
    return parseFloat((copia.reduce((acc, x) => acc + x.imc, 0) / copia.length).toFixed(1))
}

const pacientesProcessados = Object.freeze(processarPacientes(inputStr))

console.log(pacientesProcessados)
