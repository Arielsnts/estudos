const visor = document.getElementById('visor')

function apagar() {
    visor.innerHTML = ""
}

function limparErro() {
    if (visor.textContent === "Digite um número" ||
        visor.textContent === "Infinito" ||
        visor.textContent === "Indeterminado" ||
        visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
}

function addNumero(numero) {
    limparErro()
    visor.innerHTML += numero
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
    if (visor.textContent.length === 0 ||
        visor.textContent === "Digite um número") {
        visor.innerHTML = "Digite um número";
    }
    else {
        visor.innerHTML += operação
    }
}

function divisao() {addOperacao("/")}
function multiplicacao() {addOperacao("*")}
function mais() {addOperacao("+")}
function menos() {addOperacao("-")}


function ponto() {
    const ultimoNumero = visor.textContent.split(/[\+\-\*\/\(]/).pop()
    
    if (visor.textContent.length === 0 ||
        visor.textContent === "Digite um número" ||
        ultimoNumero.includes(".")) {
        visor.textContent = "Digite um número"
    } else {
        visor.innerHTML += "."
    }
}

// Daqui pra frente usei chatGPT pq não sabia fazer ainda

function porcentagem() {
    let conteudoVisor = visor.textContent.trim();

    if (conteudoVisor.length === 0 || conteudoVisor === "Digite um número") {
        visor.innerHTML = "Digite um número";
        return;
    }

    let regex = /(\d+(\.\d+)?)(?!.*\d)/;
    let match = conteudoVisor.match(regex);

    if (match) {
        let ultimoNumero = match[1];
        visor.innerHTML = conteudoVisor.replace(ultimoNumero, `(${ultimoNumero} / 100)`);
    }
}

let abrirParenteses = 0; 

function parenteses() {
    let visorTexto = visor.textContent.trim();

    if (visorTexto === "" || visorTexto === "Digite um número") {
        visor.innerHTML = "(";
        abrirParenteses = 1;
    } else if (abrirParenteses > 0 && /[\d\)]$/.test(visorTexto)) {
        visor.innerHTML += ")";
        abrirParenteses = 0;
    } else {
        visor.innerHTML += "(";
        abrirParenteses++;
    }
}

function maismenos() {
    let conteudoVisor = visor.textContent.trim();

    if (conteudoVisor.length === 0 || conteudoVisor === "Digite um número") {
        visor.innerHTML = "Digite um número";
        return;
    }

    let regex = /(\d+(\.\d+)?)(?!.*\d)/;
    let match = conteudoVisor.match(regex);

    if (match) {
        let ultimoNumero = match[1];
        let numeroNegativo = `(${parseFloat(ultimoNumero) * -1})`;
        visor.innerHTML = conteudoVisor.slice(0, match.index) + numeroNegativo;
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