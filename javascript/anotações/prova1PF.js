// Ariel Santos Souza

// Questão 1
function dividir(x, y) {
    if (y == 0) return "ERRO! O denominador não pode ser igual a zero!"
    else return x/y
  }
  
  // Testes
  console.log(dividir(1, 0))
  console.log(dividir(10, 5))
  
  // Questão 2
  const dias = (mes) => {
    if (mes == "janeiro" || mes == "março" || mes == "maio") return `O mês de ${mes} possui 31 dias!`
    else if (mes == "julho" || mes == "agosto" || mes == "outubro" || mes == "dezembro") return `O mês de ${mes} possui 31 dias!`
    else if (mes == "abril" || mes == "junho" || mes == "setembro" || mes == "novembro") return `O mês de ${mes} possui 30 dias!`
    else if (mes == "fevereiro") return `O mês de ${mes} possui 28 dias!`
  }
  
  // Testes
  // Para meses com 31 dias
  console.log(dias("janeiro"))
  console.log(dias("março"))
  
  // Para meses com 30 dias
  console.log(dias("abril"))
  console.log(dias("junho"))
  
  // Para fevereiro
  console.log(dias("fevereiro"))
  
  // Questão 3
  const ponderada = (p1) => (p2) => (p3) => (n1) => (n2) => (n3) => {
    const media = ((n1 * p1) + (n2 * p2) + (n3 * p3)) / (p1 + p2 + p3)
    return `O resultado para a média calculada é ${media.toFixed(1)}`
  }
  
  const aritmetica = ponderada(1)(1)(1)
  
  // Testes
  console.log(ponderada(1)(2)(3)(4)(5)(6))
  console.log(aritmetica(5)(6)(7))
  
  // Questão 4
  const generica = (f) => (g) => (x, y) => g(f(x) + f(y))
  
  const hipotenusa = generica((x) => x**2)((y) => y ** 0.5)
  
  // Testes
  console.log(hipotenusa(3, 4))
  console.log(hipotenusa(6, 8))