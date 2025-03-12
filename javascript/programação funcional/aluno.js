const aluno = (nome, idade, matricula, curso) => ({ nome, idade, matricula, curso })

const turma = Object.freeze([
    aluno("Mateus", 20, 101, "EC"),
    aluno("Anna", 22, 102, "SI")
])

const adicionarAluno = (lista, nome, idade, matricula, curso) => {
    return [...lista, aluno(nome, idade, matricula, curso)]
}

const listarAlunos = (lista) => lista

const buscaPorCurso = (lista, curso) => {
    const saida = [...lista]
    return saida.filter(aluno => aluno.curso == curso)
}

const removerAluno = (lista, nome) => {
    const saida = [...lista]
    return saida.filter(aluno => aluno.nome !== nome)
}

const ordenarPorMatricula = (lista) => {
    const saida = [...lista]
    return saida.sort((a, b) => a.matricula - b.matricula)
}

const contarAlunosPorCurso = (lista) => {
    const saida = [...lista]
    return saida.reduce((contador, aluno) => {
        contador[aluno.curso] = (contador[aluno.curso] || 0) + 1
        return contador
    }, {})
}

const editarAluno = (lista, nome, novosDados) => {
    return lista.map(aluno => 
        aluno.nome == nome ? { ...aluno, ...novosDados } : aluno
    )
}

const novaTurma = adicionarAluno(turma, "Carlos", 19, 103, "SI")

console.log(listarAlunos(novaTurma))

console.log(buscaPorCurso(novaTurma, "SI"))

console.log(removerAluno(novaTurma, "Carlos"))

console.log(ordenarPorMatricula(novaTurma))

console.log(contarAlunosPorCurso(novaTurma))

console.log(editarAluno(novaTurma, "Carlos", {idade: 20, curso: "EC" }))
