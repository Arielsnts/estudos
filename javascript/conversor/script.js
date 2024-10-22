const conversor = document.getElementById("conversor")
let taxa = 0.18
let codigo = "&#36;"

function trocaMoeda(moeda, valor, código) {
    taxa = valor
    codigo = código

    conversor.innerHTML = `
    <h1>Conversor</h1>
    <h2>Real para ${moeda}</h2>

    <div class="entrada" id="entrada">
        <label for="real">Digite o valor em reais:<br></label>
        <input type="number" name="real" id="real" step="any"> R<span>&#36;</span>
        <input onclick="converter()" type="button" id="botao" value="Converter">
    </div>

    <div class="resultado" id="resultado">
        <h2>Conversão:</h2>
        <p id="valor">R<span>&#36;</span> 1 ≈ <span>${código}</span> ${valor}</p>
    </div>
    `
}

function converter() {
    const resultado = document.getElementById("valor")
    const real = parseFloat(document.getElementById("real").value)

    if (isNaN(real) || real <= 0) {
        resultado.textContent = "Digite um número maior que zero"
    } else {
        const calculo = real * taxa
        resultado.innerHTML = `
        R<span>&#36;</span> ${real.toFixed(2)} ≈ <span>${codigo}</span> ${calculo.toFixed(2)}
        `
    }
}