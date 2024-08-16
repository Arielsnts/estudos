// Funções com pârametros desagregados para calcular os juros simples, compostos e montante final
const jurosSimples = (tempo) => (valor) => (taxa) => valor * taxa * tempo
const jurosCompostos = (tempo) => (valor) => (taxa) => ((valor * (1 + taxa) ** tempo) - valor).toFixed()
const montanteFinal = (fJuros) => (tempo) => (valor) => (taxa) => (valor + parseFloat(fJuros(tempo)(valor)(taxa))).toFixed()

// Funções parciais para calcular o juros simples pra 1 ano e o composto pra 6 meses
const js1ano = jurosSimples(12)
const jc6meses = jurosCompostos(6)

// Testes
console.log(jurosSimples(5)(800)(2/100))
console.log(jurosCompostos(4)(2000)(0.03))
console.log(montanteFinal(jurosCompostos)(4)(2000)(0.03))

console.log(js1ano(800)(2/100))
console.log(jc6meses(2000)(0.03))
