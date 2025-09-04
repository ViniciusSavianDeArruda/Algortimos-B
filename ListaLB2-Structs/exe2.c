/*Desenvolva um algoritmo para controlar os dados de uma turma ofertada em um determinado
semestre, para a graduação em Ciência da Computação. A turma possui: código (inteiro), nome
da disciplina (até 50 caracteres), carga horária em horas (inteiro), nome do professor (até 60

caracteres), até 40 alunos (um vetor para armazenar a matrícula de cada aluno da turma) e a
quantidade de presenças de cada aluno. Leia os dados da turma e, posteriormente, apresente:
1.Os dados da turma (código, nome disciplina, carga horária e professor).
2.A quantidade de alunos matriculados na turma.
3. A matrícula de cada aluno e seu percentual de frequência.
4. O valor médio da frequência dos alunos da turma.

*/
/*#include <stdio.h>

struct Aluno {
    int matricula;
    int presencas;
};

struct Turma {
    int codigo;
    char nome_disciplina[51];
    int cargaHoraria;
    char professor[61];
    struct Aluno alunos[40];
    int numAlunos;
    float mediaFrequencia;
};

int main(){
    struct Turma turma;
    int i;

    turma.mediaFrequencia = 0.0;  // inicializa a média

    printf("Digite o codigo da turma: ");
    scanf("%d", &turma.codigo);
    getchar();  // limpar buffer

    printf("Digite o nome da disciplina: ");
    scanf("%[^\n]", turma.nome_disciplina);
    getchar();

    printf("Digite a carga horaria: ");
    scanf("%d", &turma.cargaHoraria);
    getchar();

    printf("Digite o nome do professor: ");
    scanf("%[^\n]", turma.professor);
    getchar();

    printf("Digite a quantidade de alunos na turma (ate 40): ");
    scanf("%d", &turma.numAlunos);

    for(i = 0; i < turma.numAlunos; i++){
        printf("Digite a matricula do aluno %d: ", i + 1);
        scanf("%d", &turma.alunos[i].matricula);

        printf("Digite a quantidade de presencas do aluno %d: ", i + 1);
        scanf("%d", &turma.alunos[i].presencas);
    }

    printf("\nDados da turma:");
    printf("\nCodigo: %d", turma.codigo);
    printf("\nDisciplina: %s", turma.nome_disciplina);
    printf("\nCarga Horaria: %d", turma.cargaHoraria);
    printf("\nProfessor: %s", turma.professor);

    printf("\nQuantidade de alunos: %d", turma.numAlunos);
    printf("\nMatriculas e frequencias:");

    for(i = 0; i < turma.numAlunos; i++){
        float percentual = (float)turma.alunos[i].presencas / turma.cargaHoraria * 100;
        printf("\nMatricula: %d | Frequencia: %.2f%%", turma.alunos[i].matricula, percentual);
        turma.mediaFrequencia += percentual;
    }

    turma.mediaFrequencia /= turma.numAlunos;
    printf("\nMedia de frequencia da turma: %.2f%%\n", turma.mediaFrequencia);

    return 0;
}*/




