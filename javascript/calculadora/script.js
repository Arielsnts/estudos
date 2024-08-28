const visor = document.getElementById('visor')

function apagar() {
    visor.innerHTML = ""
}

function zero() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "0"
}

function um() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "1"
}

function dois() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "2"
}

function tres() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "3"
}

function quatro() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "4"
}

function cinco() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "5"
}

function seis() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "6"
}

function sete() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "7"
}

function oito() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "8"
}

function nove() {
    if (visor.textContent === "Digite um número" || visor.textContent === "Infinito" || visor.textContent === "Indeterminado" || visor.textContent === "Erro") {
        visor.innerHTML = ""
    }
    visor.innerHTML += "9"
}

function divisao() {
    if (visor.textContent.length === 0 || visor.textContent === "Digite um número") {
        visor.innerHTML = "Digite um número";
    } else {
        visor.innerHTML += " / ";
    }
}

function multiplicacao() {
    if (visor.textContent.length === 0 || visor.textContent === "Digite um número") {
        visor.innerHTML = "Digite um número";
    } else {
        visor.innerHTML += "*";
    }
}

function mais() {
    if (visor.textContent.length === 0 || visor.textContent === "Digite um número") {
        visor.innerHTML = "Digite um número";
    } else {
        visor.innerHTML += " + ";
    }
}

function menos() {
    if (visor.textContent.length === 0 || visor.textContent === "Digite um número") {
        visor.innerHTML = "Digite um número";
    } else {
        visor.innerHTML += " - ";
    }
}

// Daqui pra frente usei chatGPT pq não sabia fazer ainda

function ponto() {
    let conteudoVisor = visor.textContent.trim();
    let ultimoNumero = conteudoVisor.split(/[\+\-\*\/\(\s]/).pop(); // Extrai o último número

    if (conteudoVisor.length === 0 || 
        conteudoVisor === "Digite um número" || 
        ultimoNumero.includes(".")) {
        visor.innerHTML = "Digite um número";
    } else {
        visor.innerHTML += ".";
    }
}

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