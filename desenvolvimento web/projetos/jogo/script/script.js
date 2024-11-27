const quadrado = document.querySelector('.quadrado')

function pulo() {
    quadrado.classList.add('pulo')

    setTimeout(() => {
        quadrado.classList.remove('pulo')
    }, 750)
}


document.addEventListener('keydown', pulo)