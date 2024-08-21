function confirmar() {
    let numero = Number(document.getElementById('numero').value)
    let tabela1 = document.getElementById('tabela1')
    let tabela2 = document.getElementById('tabela2')
    
    tabela1.innerHTML = ''
    tabela2.innerHTML = ''

    if (isNaN(numero)) {
        resultado.innerHTML = "ERRO! Você não digitou um número!"
    } else {
        for (let contador = 1; contador <= 5; contador++) {
            tabela1.innerHTML += `${contador} x ${numero} = ${contador * numero} <br>`
        }
        for (let contador = 6; contador <= 10; contador++) {
            tabela2.innerHTML += `${contador} x ${numero} = ${contador * numero} <br>`
        }
    }
}
