//7. Desenvolva um programa para ler a carga horária (em horas) de uma disciplina e a quantidade faltas de um estudante. Em uma função, calcule e retorne o percentual de frequência do
//estudante. A função main exibe o percentual de frequência na tela.

#include <stdio.h>

double percentualFrequencia(int cargaHoraria, int faltas) {
    return ((cargaHoraria - faltas) / (float)cargaHoraria) * 100;
}

int main() {
    int carga, faltas;

    printf("Digite a carga horaria da disciplina: ");
    scanf("%d", &carga);

    printf("Digite a quantidade de faltas do aluno: ");
    scanf("%d", &faltas);

    printf("Percentual de frequencia do aluno: %.2f%%\n", (double)percentualFrequencia(carga, faltas));

    return 0;
}