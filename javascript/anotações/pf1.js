const executar = (f, x, y, z) => f(x, y, z)

console.log(executar((x, y) => x*y**2, 3.14, 5))
