const carrinho = [
    {nome:"caneta", qtde:10, preco:7.99, fragil: true},
    {nome:"impressora", qtde:1, preco:649.50, fragil: true},
    {nome:"caderno", qtde:4, preco:27.10, fragil: false},
    {nome:"lapis", qtde:3, preco:5.82, fragil: false},
    {nome:"tesoura", qtde:1, preco:19.20, fragil: true}
]

const parcial = (registro) => registro.qtde * registro.preco
const soma = (acc, x) => acc + x
const fragil = (registro) => registro.fragil
const dolar = (registro) => registro.preco / 5.65
const desconto20 = (registro) => registro.preco * 0.8
const letraC = (registro) => registro.nome[0] == "c"
const qtde = (registro) => registro.qtde

// letra a
console.log(carrinho.map(dolar))
// letras b e d
console.log(carrinho.filter(fragil).map(parcial).reduce(soma, 0))
// letra c
console.log(carrinho.map(desconto20))
// letra e
console.log(carrinho.filter(letraC).map(parcial).reduce(soma, 0))
// letra f
console.log(carrinho.filter(fragil).map(parcial).reduce(soma, 0) / carrinho.filter(fragil).map(qtde).reduce(soma,0))
