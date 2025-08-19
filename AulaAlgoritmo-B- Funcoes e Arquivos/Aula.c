//Aula algoritmos B -  dia 19/08/25

//Desafio: Implemenar a solucao do problemas da lista 1b usando structs e arquivos

//Arquivos 
//Para que serve os arquivos?
//Para armazenar dados de forma permanente, mesmo quando o programa é fechado.

//1 Declarar a variavel do tipo arquivo
// 2 criar/ abrir o arquivo fopen 
// 3 gravar os dados ou ler os dados  fprintf
// 4 fechar o arquivo fclose 


//EXEMPLOS SOBRE ARQUIVOS

//ESSE ARQUIVO É UM EXEMPLO DE COMO CRIAR UM ARQUIVO E GRAVAR DADOS NELE
//O ARQUIVO É CRIADO NO MESMO DIRETÓRIO DO PROGRAMA
/*#include <stdio.h>

struct produto{
    char tipo[50];
    int ano;
};

int main(){
    struct produto a[3];
    int i;
    FILE *arquivo;

    for(i=0; i<3; i++){
        printf("Tipo Produto: ");
        scanf("%s", a[i].tipo);
        printf("Ano: ");
        scanf("%i", &a[i].ano);
        printf("\n");
    }

    printf("Dados:\n");
    for(i=0; i<3; i++){
        printf("%s\n", a[i].tipo);
        printf("%i\n", a[i].ano);
    }

    arquivo = fopen("dados.txt", "w");

    if (!arquivo){
        printf("Erro na abertura do arquivo!!!");
        exit(-1);
    }

    for(i=0; i<3; i++){
        fprintf(arquivo, "%s\n", a[i].tipo);
        fprintf(arquivo, "%i\n", a[i].ano);
    }

    fclose(arquivo);

    return 0;
}*/


/*#include <stdio.h>
#include <stdlib.h>

struct produto {
    char tipo[50];
    int ano;
};

int main() {
    struct produto a[3];
    int i, q=0,sair=1;
    FILE *arquivo;

    arquivo = fopen("dados.txt", "r");

    if (!arquivo) {
        printf("Erro na abertura do arquivo!!!\n");
        exit(-1);
    }


   for (i = 0; i < 3; i++) {
        if (fscanf(arquivo, "%s %d", a[i].tipo, &a[i].ano) !=2){
            printf("Término da leitura");
        }
    }

    fclose(arquivo);


    printf("Dados lidos do arquivo:\n");
    for (i = 0; i < 3; i++) {
        printf("%s %d\n", a[i].tipo, a[i].ano);
    }

    return 0;
}
*/


/*#include <stdio.h>
#include <stdlib.h>

struct produto {
    char tipo[50];
    int ano;
};

int main() {
    struct produto a[10];
    int i, q,sair=1;
    FILE *arquivo;

    arquivo = fopen("dados.txt", "r");

    if (!arquivo) {
        printf("Erro na abertura do arquivo!!!\n");
        exit(-1);
    }


   for (q = 0; sair == 1; q++) {
        if (fscanf(arquivo, "%s %d", a[q].tipo, &a[q].ano) !=2){
            printf("Término da leitura");
            sair = 0;
        }
    }

    fclose(arquivo);


    printf("Dados lidos do arquivo:\n");
    for (i = 0; i < q-1; i++) {
        printf("%s %d\n", a[i].tipo, a[i].ano);
    }

    return 0;
}
*/
//Esse exemplo lê dados de um arquivo e imprime na tela
//O arquivo "dados.txt" deve existir no mesmo diretório do programa e conter os dados

//==========================================================================================//


//FUNCOES EM C 
//Funções são blocos de código que realizam uma tarefa específica
//Podem receber parâmetros e retornar valores
//Podem ser usadas para organizar o código e evitar repetição
//E podem ser reutilizadas em diferentes partes do programa
//Funcoes podem returnar valores como inteiros, floats, doubles, etc.
//Declarar uma funcao signfica definir seu nome, especificar o algoritmo e o tipo de retorno