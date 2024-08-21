function contar() {
    var inicio = Number(document.getElementById('inicio').value);
    var fim = Number(document.getElementById('fim').value);
    var passo = Number(document.getElementById('passo').value);
    var resultado = document.getElementById('resultado');

    resultado.innerHTML = `Contagem: `;

    if (isNaN(inicio) || isNaN(fim) || isNaN(passo) || passo <= 0) {
        window.alert('ERRO! Dados insuficientes ou passo inválido!');
        resultado.innerHTML = `Contagem: `;
    } else {
        if (inicio < fim) {
            // Contagem crescente
            for (let contagem = inicio; contagem <= fim; contagem += passo) {
                resultado.innerHTML += `${contagem} `;
            }
        } else {
            // Contagem decrescente
            for (let contagem = inicio; contagem >= fim; contagem -= passo) {
                resultado.innerHTML += `${contagem} `;
            }
        }
    }
}