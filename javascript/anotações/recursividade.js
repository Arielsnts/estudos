const lista = [1, 2, 3, 4, 5]

const indef = (x) => typeof x == "undefined"

const ordemSequencia = (num) => {
    if (num == 1) return 3
    else return 2 * ordemSequencia(num - 1)
}

const fibonacci = (num) => {
    if (num == 1) return 1
    if (num == 2) return 1
    else return fibonacci(num - 1) + fibonacci(num - 2)
}

const somaDosNaturais = (num) => {
    if (num == 1) return 1
    else return num + somaDosNaturais(num - 1)
}

const fatorial = (num) => {
    if (num == 0) return 1
    else return num * fatorial(num - 1)
}

const potenciaDo2 = (num) => {
    if (num == 0) return 1
    else return 2 * potenciaDo2(num - 1)
}

const restoDaDivisao = (n, m) => {
    if (n < m) return n
    else return restoDaDivisao(n - m, m)
}

const quociente = (n, m) => {
    if (n < m) return 0
    else return 1 + quociente(n - m, m)
}

const mdc = (n, m) => {
    if (m == 0) return n
    if (n < m) return mdc(m, n)
    else return mdc(n - m, m)
}

const tamanho = (string) => {
    if (string == "") return 0
    else return 1 + tamanho(string.slice(1))
}

const soma = ([head, ...tail]) => indef(head) ? 0 : (head + soma(tail))

const inverte = ([head, ...tail]) => {
    if (indef(head)) return []
    else return [...inverte(tail), head]
}

const len = ([head, ...tail]) => {
    if (indef(head)) return 0
    else return 1 + len(tail)
}

// Testes 
console.log(len(lista))