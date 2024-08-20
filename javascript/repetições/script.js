function contar() {
    var inicio = Number(document.getElementById('inicio').value)
    var fim = Number(document.getElementById('fim').value)
    var passo = Number(document.getElementById('passo').value)
    var resultado = document.getElementById('resultado')

    resultado.innerHTML = `Contagem: `
    if (inicio.length == 0 || fim.length == 0 || passo.length == 0) {
        window.alert('ERRO! Dados insuficientes!')
        resultado.innerHTML = `Contagem: `
    } else {
        if (inicio < fim) {
            for (let contagem = inicio; contagem <= fim; contagem += passo) {
                resultado.innerHTML += `${contagem} ` 
            }
        } else {
            for (let contagem = inicio; contagem >= fim; contagem -= passo) {
                resultado.innerHTML += `${contagem} ` 
            }
        }
    } 
}