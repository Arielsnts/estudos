const readline = require('readline');

function fatorial(num) {
    let resultado = 1;
    for (let i = 1; i <= num; i++) {
        resultado *= i;
    }
    return resultado;
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Escolha um número inteiro: ', (input) => {
    const escolha = parseInt(input);
    const resposta = fatorial(escolha);

    console.log(`O fatorial de ${escolha} é ${resposta}!`);
    rl.close();
});