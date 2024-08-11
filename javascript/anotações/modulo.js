const somaF = (f) => (x) => (y) => (z) => f(x) + f(y) + f(z)
console.log(somaF((x) => x < 0 ? -x : x)(-3)(2)(1))
