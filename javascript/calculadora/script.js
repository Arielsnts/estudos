const visor = document.getElementById('visor')

function apagar() {
    visor.innerHTML = ""
}

function verificaErro() {
    if (visor.textContent === "Digite um número" ||
        visor.textContent === "Infinito" ||
        visor.textContent === "Indeterminado" ||
        visor.textContent === "Erro") return true
    else return false
}

function addNumero(numero) {
    if (verificaErro()) {
        visor.textContent = numero
    } else return visor.textContent += numero
} 

function zero() {addNumero("0")}
function um() {addNumero("1")}
function dois() {addNumero("2")}
function tres() {addNumero("3")}
function quatro() {addNumero("4")}
function cinco() {addNumero("5")}
function seis() {addNumero("6")}
function sete() {addNumero("7")}
function oito() {addNumero("8")}
function nove() {addNumero("9")}

function addOperacao(operação) {
    if (visor.textContent.length === 0 || verificaErro()) {
        visor.textContent = "Digite um número";
    }
    else {
        visor.textContent += operação
    }
}

function divisao() {addOperacao("/")}
function multiplicacao() {addOperacao("*")}
function mais() {addOperacao("+")}
function menos() {addOperacao("-")}


function ponto() {
    const ultimoNumero = visor.textContent.split(/[\+\-\*\/\(]/).pop()
    
    if (visor.textContent.length === 0 ||  verificaErro() ||
        ultimoNumero.includes(".")) {
        visor.textContent = "Digite um número"
    } else {
        visor.textContent += "."
    }
}

function porcentagem() {
    if (visor.textContent.length === 0 || verificaErro()) {
        visor.textContent = "Digite um número"
        return
    }

    const regex = visor.textContent.match(/(\d+(\.\d+)?)(?!.*\d)/)

    if (regex) {
        const ultimoNumero = regex[0]
        visor.textContent = visor.textContent.replace(ultimoNumero, `(${ultimoNumero} / 100)`)
    }
    // Pode ocorrer um erro de substituição caso a função tente substituir um número com mais de uma ocorrência.
}

function maismenos() {
    if (visor.textContent.length === 0 || verificaErro()) {
        visor.textContent = "Digite um número"
        return
    }

    const regex = visor.textContent.match(/(\d+(\.\d+)?)(?!.*\d)/)

    if (regex) {
        const ultimoNumero = regex[0]
        visor.textContent = visor.textContent.replace(ultimoNumero, `(${ultimoNumero * -1})`)
    }
    // Pode ocorrer um erro de substituição caso a função tente substituir um número com mais de uma ocorrência.
}

let abrirParenteses = 0; 

function parenteses() {
    if (visor.textContent.length === 0 || verificaErro()) {
        visor.textContent = "("
        abrirParenteses = 1
    } else if (abrirParenteses > 0 && /[\d\)]$/.test(visor.textContent)) {
        visor.textContent += ")"
        abrirParenteses = 0
    } else {
        visor.textContent += "("
        abrirParenteses++
    }
}

function igual() {
    try {
        let resultado = eval(visor.textContent);
        if (isNaN(resultado)) {
            visor.innerHTML = "Indeterminado";
        } else if (!isFinite(resultado)) {
            visor.innerHTML = "Infinito";
        } else {
            visor.innerHTML = resultado;
        }
    } catch (e) {
        visor.innerHTML = "Erro";
    }
}