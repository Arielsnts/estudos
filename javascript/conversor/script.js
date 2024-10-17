const conversor = document.getElementById("conversor")

function trocaMoeda(moeda, taxa, código) {
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
                <p id="valor">R<span>&#36;</span> 1 ≈ <span>${código}</span> ${taxa}</p>
            </div>
    `
}

function dolar() {trocaMoeda("dólar", 0.18, "&#36;")}
function euro() {trocaMoeda("euro", 0.16, "&#8364;")}
function iene() {trocaMoeda("iene", 26.47, "&#165;")}
function argentina() {trocaMoeda("peso argentino", 172.73, "&#36;")}
function libra() {trocaMoeda("libra esterlina", 0.14, "&#163;")}

function converter() {
    const resultado = document.getElementById("valor")
    const real = parseFloat(document.getElementById("real").value)
    
    let taxa = 0
    if (resultado.textContent.includes(0.18)) {taxa = 0.18}
    else if (resultado.textContent.includes(0.16)) {taxa = 0.16}
    else if (resultado.textContent.includes(26.47)) {taxa = 26.37}
    else if (resultado.textContent.includes(172.73)) {taxa = 172.73}
    else if (resultado.textContent.includes(0.14)) {taxa = 0.14}

    if (isNaN(real) || real <= 0) {
        resultado.textContent = "Digite um número maior que zero"
    } else {
        const calculo = real * taxa
        resultado.innerHTML = `
        <p id="valor">R<span>&#36;</span> ${real.toFixed(2)} ≈ <span>&#36;</span> ${calculo.toFixed(2)}</p>
        `
    }
}