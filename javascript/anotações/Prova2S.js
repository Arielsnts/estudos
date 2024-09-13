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

console.log(pacientesProcessados)

