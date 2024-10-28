let ativado = false
const usuario = document.getElementById("usuario")
const maquina = document.getElementById("maquina")
const mensagem = document.getElementById("mensagemFinal")

/* 1 = pedra, 2 = papel, 3 = tesoura*/

function jogo(botao, escolhaUsuario) {
    if (ativado) return

    botao.classList.add("clicado")
    ativado = true

    setTimeout(() => {
        usuario.innerHTML = `
        <div class="quadros" id="usuario"> VOCÊ ESCOLHEU:
            <div>${escolhaUsuario}</div>
        </div>
        `
        usuario.classList.add("escolhido")
    }, 250)

    const escMaquina = escolhaMaquina().toLowerCase()

    setTimeout(() => {
        maquina.innerHTML = `
        <div class="quadros" id="maquina">EU ESCOLHI:
            <div>${escMaquina}</div>
        </div>
        `
        maquina.classList.add("escolhido")
    }, 1500)

    mensagem.style.display = "block"

    setTimeout(() => {
        if (escolhaUsuario == escMaquina) {
            mensagem.innerHTML = `
                <h2>EMPATE!</h2>
            `
        } else if (
            (escolhaUsuario === "pedra" && escMaquina === "tesoura") ||
            (escolhaUsuario === "papel" && escMaquina === "pedra") ||
            (escolhaUsuario === "tesoura" && escMaquina === "papel")
        ) {
            mensagem.innerHTML = `
                <h2>VOCÊ VENCEU!</h2>
            `
        } else {
            mensagem.innerHTML = `
                <h2>VOCÊ PERDEU!</h2>
            `
        }

        mensagem.innerHTML += `<button id="reiniciar" onclick="recarregar()">REINICIAR</button>`
    }, 2700)
}

function escolhaMaquina() {
    const random = Math.floor(Math.random() * 3) + 1

    if (random == 1) return "pedra"
    else if (random == 2) return "papel"
    else return "tesoura"
}

function recarregar() {
    location.reload()
}
