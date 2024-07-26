function quadratica(a, b, c) {
    const delta = b ** 2 - 4 * a * c
    if (delta < 0) return "Não possui raízes reais!"

    const raizX1 = (-b + Math.sqrt(delta)) / 2 * a
    const raizX2 = (-b - Math.sqrt(delta)) / 2 * a
    return `As raízes da equação são ${raizX1} e ${raizX2}!`
}

console.log(quadratica(1, -5, 6))