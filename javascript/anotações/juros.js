const final = (meses) => (taxa) => (inicial) => inicial * (1 + taxa/100) ** meses
const final1ano = final(12)

console.log(final1ano(1)(1000).toFixed())
