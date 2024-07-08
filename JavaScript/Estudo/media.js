function calcularMedia(n1, n2, n3) {
    return (n1 + n2 + n3) / 3;
}

function determinarSituacao(media, faltas) {
    if (media >= 7 && faltas <= 15) {
        return 'Aprovado!';
    } else if (media >= 5 && faltas <= 7) {
        return 'Aprovado!';
    } else {
        return 'Reprovado!';
    }
}

const n1 = 6;
const n2 = 8;
const n3 = 5;
const faltas = 5;
const media = calcularMedia(n1, n2, n3);
const situacao = determinarSituacao(media, faltas);

console.log(`Sua média foi ${media.toFixed(2)}, seu número de faltas foi ${faltas} e você foi ${situacao}`);