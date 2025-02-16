#include <stdio.h>

int main() {
    int aluno, voltas;

    scanf("%d%*c%d", &aluno, &voltas);

    int listaAluno[aluno];

    for (int i = 0; i < aluno; i++) listaAluno[i] = i+1;

    int conjuntoAlunos[aluno][voltas];
    int soma[aluno];

    for (int i = 0; i < aluno; i++) soma[i] = 0;

    for (int i = 0; i < aluno; i++) {
        for(int j = 0; j < voltas; j++) {
            scanf("%d%*c", &conjuntoAlunos[i][j]);
            soma[i] += conjuntoAlunos[i][j];
        }
    }

    int menorTempo = soma[0];
    int vencedor = 1;

    for (int i = 1; i < aluno; i++) {
        if (soma[i] < menorTempo) {
            menorTempo = soma[i];
            vencedor = i+1;
        }
    }

    printf("%d\n", vencedor);
    
    return 0;
}