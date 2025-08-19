/*Desenvolva um algoritmo para controlar a quantidade de produtos existentes em uma
    Papelaria. Considere que cada produto possui: código (inteiro), nome (até 30 caracteres),
    unidade (até 20 caracteres), preço custo, preço de venda e quantidade em estoque. As
    seguintes funcionalidades devem estar implementadas:

* Ler os dados dos produtos informados pelo usuário, enquanto o usuário desejar digitar
(pode ser feita uma pergunta ao usuário, se deseja cadastrar mais um produto).
* Para o preço de venda, solicitar ao usuário o percentual de lucro desejado sobre o preço
de custo (o mesmo percentual é aplicado a todos os produtos).
* Após a leitura, o usuário pode escolher as opções desejadas:

a. Listar os dados de todos os produtos.
b. Listar os dados de um produto, conforme o código digitado pelo usuário.
c. Listar os produtos cuja quantidade em estoque é zero.
d. Mostrar os dados do produto de maior valor de venda.
e. Mostrar os dados do produto de menor valor de venda.*/

/*#include <stdio.h>

struct Produto {
    int codigo;
    char nome[30];
    char unidade[30];
    float precoCusto;
    float precoVenda;
    int quantidadEstoque;
};

int main() {
    struct Produto produtos[100];
    float percentualLucro;
    int opcao;
    int totalProdutos = 0;
    int continuar;
    int idx = 0;
    int i;

    printf("Digite o percentual de lucro desejado: ");
    scanf("%f", &percentualLucro);
    getchar(); 

    do {
        printf("\n---Cadastro de Produtos---\n");

        printf("Digite o codigo do produto: ");
        scanf("%d", &produtos[totalProdutos].codigo);
        getchar(); // limpa o \n do buffer

        printf("Digite o nome do produto: ");
        scanf(" %[^\n]", produtos[totalProdutos].nome); 

        printf("Digite a unidade do produto: ");
        scanf(" %[^\n]", produtos[totalProdutos].unidade);

        printf("Digite o preco de custo do produto: ");
        scanf("%f", &produtos[totalProdutos].precoCusto);

        produtos[totalProdutos].precoVenda = produtos[totalProdutos].precoCusto * (1 + percentualLucro / 100);

        printf("Digite a quantidade em estoque do produto: ");
        scanf("%d", &produtos[totalProdutos].quantidadEstoque);
        getchar(); 

        totalProdutos++;

        printf("Deseja cadastrar outro produto (1-sim / 0-nao): ");
        scanf("%d", &continuar);
        getchar(); 
    } while (continuar && totalProdutos < 100);


    do {
        printf("\n---Menu de Opcoes---\n");
        printf("1. Listar todos os produtos\n");
        printf("2. Buscar produto por codigo\n");
        printf("3. Listar produtos sem estoque\n");
        printf("4. Mostrar produto mais caro\n");
        printf("5. Mostrar produto mais barato\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            for ( i = 0; i < totalProdutos; i++)
                printf("%d | %s | %s | Custo: %.2f | Venda: %.2f | Estoque: %d\n",
                       produtos[i].codigo, produtos[i].nome, produtos[i].unidade,
                       produtos[i].precoCusto, produtos[i].precoVenda,
                       produtos[i].quantidadEstoque);
        }
        else if (opcao == 2) {
            int cod, achou = 0;
            printf("Digite o codigo: ");
            scanf("%d", &cod);
            getchar();

            for (i = 0; i < totalProdutos; i++) {
                if (produtos[i].codigo == cod) {
                    printf("%d | %s | %s | Custo: %.2f | Venda: %.2f | Estoque: %d\n",
                           produtos[i].codigo, produtos[i].nome, produtos[i].unidade,
                           produtos[i].precoCusto, produtos[i].precoVenda,
                           produtos[i].quantidadEstoque);
                    achou = 1;
                    break;
                }
            }
            if (!achou) printf("Produto nao encontrado.\n");
        }
        else if (opcao == 3) {
            for ( i = 0; i < totalProdutos; i++)
                if (produtos[i].quantidadEstoque == 0)
                    printf("%d | %s\n", produtos[i].codigo, produtos[i].nome);
        }
        else if (opcao == 4 || opcao == 5) {
            if (totalProdutos == 0) {
                printf("Nenhum produto cadastrado.\n");
                continue;
            }
            for ( i = 1; i < totalProdutos; i++)
                if ((opcao == 4 && produtos[i].precoVenda > produtos[idx].precoVenda) ||
                    (opcao == 5 && produtos[i].precoVenda < produtos[idx].precoVenda))
                    idx = i;
            printf("%d | %s | Venda: %.2f\n", produtos[idx].codigo, produtos[idx].nome, produtos[idx].precoVenda);
        }
    } while (opcao != 0);

    return 0;
}*/


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








