const inputStr = ["Maria tem média 7.8.", "6.7 foi a média de Pedro"]

const lista = [{nome: "Maria", média: 7.8}, {nome: "Pedro", média: 6.7}]

const adicionar = (lista, aluno, media) => {
    return [...lista, {nome: aluno, média: media}]
}

console.log(adicionar(lista, "ariel", 10))