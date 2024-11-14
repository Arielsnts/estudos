const carrinho = [
    {nome:"caneta", qtde:10, preco:7.99, fragil: true},
    {nome:"impressora", qtde:1, preco:649.50, fragil: true},
    {nome:"caderno", qtde:4, preco:27.10, fragil: false},
    {nome:"lapis", qtde:3, preco:5.82, fragil: false},
    {nome:"tesoura", qtde:1, preco:19.20, fragil: true}
]

const parcial = (registro) => registro.qtde * registro.preco
const soma = (acc, x) => acc + x

const dolar = (registro) => (registro.preco / 5.64).toFixed(2)

const desconto20 = (registro) => (registro.preco * 0.80).toFixed(2)

const frageis = (registro) => registro.fragil

const letraC = (registro) => registro.nome[0] == "c"

const qtde = (registro) => registro.qtde

// letra a
console.log(carrinho.map(dolar))
// letra b
console.log(carrinho.map(parcial).reduce(soma, 0))
// letra c
console.log(carrinho.map(desconto20))
// letra d
console.log(carrinho.filter(frageis).map(parcial).reduce(soma, 0))
// letra e
console.log(carrinho.filter(letraC).map(parcial).reduce(soma, 0))
// letra f
console.log(carrinho.filter(frageis).map(parcial).reduce(soma, 0) / carrinho.filter(frageis).map(qtde).reduce(soma, 0))

console.log(carrinho.map(qtde))