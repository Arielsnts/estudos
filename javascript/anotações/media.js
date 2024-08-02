const media = (f, n1, n2, n3, p1 = 1, p2 = 1, p3 = 1) => f(n1, n2, n3, p1, p2, p3)

const situacao = (carga, faltas, media) => {
  if (media < 5) {
    return "reprovado"
  } else if (carga == 4 && faltas > 15) {
    return "reprovado"
  } else if (carga == 4 && faltas >= 8 && media < 7) {
    return "reprovado"
  } else if (carga == 6 && faltas > 22) {
    return "reprovado"
  } else if (carga == 6 && faltas >= 11 && media < 7) {
    return "reprovado"
  } else if (carga == 2 && faltas > 7) {
    return "reprovado"
  } else if (carga == 2 && faltas >= 3 && media < 7) {
    return "reprovado"
  } else return "aprovado"
}

console.log(situacao(4, 2, media((n1, n2, n3, p1, p2, p3) => (n1*p1 + n2*p2 + n3*p3) / (p1+ p2+ p3) , 4, 5, 6, 1, 1, 1)))