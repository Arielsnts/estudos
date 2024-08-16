const somaF = (f) => (x) => (y) => (z) => f(x) + f(y) + f(z)
console.log(somaF((x) => x < 0 ? -x : x)(-3)(2)(1))

const min = (a, b, c) => a(c) < b(c) ? a : b
console.log(min((x) => x ** 3, (y) => y * 3, 4)(-1))
