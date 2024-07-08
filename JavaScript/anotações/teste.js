const readline = require('readline');
const { randomInt } = require('crypto');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cont = 0;

function jogo() {
    rl.question('ÍMPAR ou PAR? [I/P]: ', (esc) => {
        esc = esc.toUpperCase().trim();
        rl.question('Digite um número inteiro de 1 a 10: ', (numInput) => {
            const num = parseInt(numInput);
            const maq = randomInt(1, 11); // Gera um número aleatório entre 1 e 10
            const soma = num + maq;

            if ((soma % 2 === 0 && esc === 'P') || (soma % 2 === 1 && esc === 'I')) {
                console.log(`Você escolheu ${num} e eu escolhi ${maq}, que resulta em ${soma}. VOCÊ GANHOU!`);
                cont++;
                jogo(); // Joga novamente
            } else {
                console.log(`Você escolheu ${num} e eu escolhi ${maq}, que resulta em ${soma}. VOCÊ PERDEU!`);
                console.log(`O número de vitórias seguidas foi ${cont}!`);
                rl.close();
            }
        });
    });
}

// Iniciar o jogo
jogo();