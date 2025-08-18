/*7 – Escreva um algoritmo para gerar os valores de um vetor numérico de 50 posições e ler um código numérico
inteiro. Se o código for zero, termine o algoritmo. Se o código for 1, mostre o vetor na ordem em que foi
gerado. Se o código for 2, mostre o vetor na ordem inversa, do último elemento até o primeiro.
*/

/*#include <stdio.h>

int main(){
    int vetor[50];
    int codigo;
    int i;

    // Gerar os valores do vetor
    for(i = 0; i < 50; i++){
        vetor[i] = i + 1; // Preenchendo o vetor com valores de 1 a 50
        
        printf("Vetor[%d] = %d\n", i, vetor[i]);

        printf("Digite um código (0 para sair, 1 para mostrar ordem normal, 2 para ordem inversa): ");
        scanf("%d", &codigo);

        if(codigo == 0){
            printf("Programa encerrado.\n");
            return 0; // Termina o programa se o código for zero
        } else if(codigo == 1){
            printf("Vetor na ordem original:\n");
            for(int j = 0; j <= i; j++){
                printf("%d ", vetor[j]);
            }
            printf("\n");
        } else if(codigo == 2){
            printf("Vetor na ordem inversa:\n");
            for(int j = i; j >= 0; j--){
                printf("%d ", vetor[j]);
            }
            printf("\n");
        } else {
            printf("Código inválido. Tente novamente.\n");
        }



    }
}
*/



//Lista 1 STRUCT
/*A turma de Algoritmos e Programação B tem 17 alunos. Para cada aluno, é necessário
armazenar o nome, número de faltas (em horas), os valores das nota 1, nota 2, nota 3 e a média
final. A média das notas é a média aritmética e deve ser calculada. Após fazer a leitura dos
valores, calcule a média das notas, para cada aluno e mostre o resultado final de acordo com as
regras:
 Para ser aprovado, o estudante deve ter 75% de frequência. Caso
contrário, está Reprovado por Frequência.
 Se o estudante tem 75% ou mais de frequência nas aulas, o resultado
é:
◦ Aprovado, se a média final for maior ou igual a 6,0 ou
◦ Reprovado, se a média final for menor que 6,0
 Para calcular a frequência, considere que a disciplina tem 80 horas.*/

/*#include <stdio.h>

struct Aluno{
    char nome[50];
    int faltas;
    float nota1, nota2, nota3, mediaFinal;

};

int main(){
    struct Aluno alunos[17];
    int i;

    for(i = 0; i < 17; i++){
        printf("Digite o nome do aluno %d:", i + 1);
        scanf("%d", &alunos[i].nome);

        printf("Digite o numero de faltas do aluno %d:", i + 1); 
        scanf("%d", &alunos[i].faltas);

        printf("Digite a nota de cada aluno  %d:", i + 1); 
        scanf("%d", &alunos[i].nota1, &alunos[i].nota2, &alunos[i].nota3);
    }

    //media das notas
    for(i = 0; i < 17; i++){
        alunos[i].mediaFinal = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3 /3.0);
    }



}
*/


//Usando struct == tipo de dado heterogeneo = Vendedor
/*#include <stdio.h>

// Definição da estrutura
struct vendedor {
    int cod;
    float salario;
    float total_vendas;
    float comissao;
};

int main() {
    struct vendedor v[4]; // array de 4 vendedores
    int i;

    // Leitura dos dados de cada vendedor
    for (i = 0; i < 4; i++) {
        printf("Codigo do Vendedor: ");
        scanf("%d", &v[i].cod);

        printf("Salario fixo: ");
        scanf("%f", &v[i].salario);

        printf("Total de vendas: ");
        scanf("%f", &v[i].total_vendas);

        // Calculo da comissão baseado no total de vendas
        if (v[i].total_vendas <= 1000) {
            printf("Comissão 3%%\n");
            v[i].comissao = v[i].total_vendas * 0.03;
        } else if (v[i].total_vendas <= 2000) {
            printf("Comissão 5%%\n");
            v[i].comissao = v[i].total_vendas * 0.05;
        } else {
            printf("Comissão 10%%\n");
            v[i].comissao = v[i].total_vendas * 0.10;
        }
        printf("\n");
    }

    // Imprimir os dados de todos os vendedores
    for (i = 0; i < 4; i++) {
        printf("Vendedor %d:\n", i+1);
        printf("Codigo do vendedor: %d\n", v[i].cod);
        printf("Salario fixo: %.2f\n", v[i].salario);
        printf("Total de vendas: %.2f\n", v[i].total_vendas);
        printf("Comissao: %.2f\n", v[i].comissao);
        printf("Salario total: %.2f\n\n", v[i].salario + v[i].comissao);
    }

    return 0;
}*/

//3 -Escrever um algoritmo para ler quatro valores inteiros, calcular a sua média, e escrever na tela os que são superiores à média.

/*#include <stdio.h>

int main(){
	
	int a, b, c, d;
	float media;
	
	printf("Digite 4 valores inteiros:");
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	media = (a + b + c + d) / 4.0;
	
	printf("Os valores superiores a media(%.2f):\n", media);
	
	if (a > media){
		printf("%d",&a);	
	}if (b > media){
		printf("%d",&b);
	}if(c > media){
		printf("%d",&c);		
	}if(d > media){
		printf("%d", &c);
	}
	
}*/



//4 – Faça um programa que leia uma palavra qualquer e depois mostre apenas as vogais.
/*#include <stdio.h>
int main(){

    char palavra[100];
    int i;

    printf("Digite qualquer palavra: ");
    scanf("%99s", palavra);

    printf("Vogais: ");
    for (i = 0; palavra[i] != '\0'; i++) {
        char c = palavra[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;0
}*/



//9- Ler uma matriz A de inteiros com ordem 10x10. Ler, a seguir, 10 valores e verificar se cada valor lido é um
//dos elementos da matriz. Se o valor for encontrado na matriz, exibir o valor encontrado e a posição do elemento
//na matriz (por exemplo: “O valor X foi encontrado na posição I,J da matriz”).

/*include <stdio.h>
int main(){
    
    int matrizA[10][10];
    int i, j, valor_encontrado = 0;


    printf("Digite os elementos da matriz 10x10:\n");

    for("i = 0; i < 10; i++"){ // for i para percorrer as linhas da matriz
        for(j = 0; j < 10; j++){ // for j para percorrer as colunas da matriz
            scanf("%d", &matrizA[i][j]);
        }
    }

    valor_encontrado = 0;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            printf("Digite um valor para verificar se está na matriz: ");
            int valor;
            scanf("%d", &valor);
            
            if(matrizA[i][j] == valor){
                printf("O valor %d foi encontrado na posicao [%d][%d] da matriz.\n", valor, i, j);
                valor_encontrado = 1;
            }
        }
    }


}*/


/*// 10- Faça um programa que gere uma matriz 4x4 com seus valores, calcule e mostre:
//A soma dos elementos da primeira coluna
//O produto dos elementos da primeira linha
//A soma da diagonal principal
//A soma de todos os elementos da matriz

include <stdio.h>
int main(){

    int matriz[4][4];
    int i, j;
    int soma_coluna = 0;
    int produto_linha = 1;
    int soma_diagonal = 0;
    int soma_total = 0;





    printf("Digite os elementos da matriz 4x4:\n");
    
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    // Soma dos elementos da primeira coluna
    for(i = 0; i < 4; i++){
        soma_coluna += matriz[i][0];
    }

    // Produto dos elementos da primeira linha
    for(j = 0; j < 4; j++){
        produto_linha *= matriz[0][j];
    }

    printf("Produto dos elementos da primeira linha: %d\n", produto_linha);


    printf("Soma dos elementos da primeira coluna: %d\n", soma_coluna);


}*/


//5 – Faça um algoritmo para ler um número menor que 1000, encontrar e mostrar todos os números ímpares maiores que o número lido e menores que 1000.

/*#include <stdio.h>
int main(){

    int numero;
    int i;

    printf("Digite um numero menor que 1000:");
    scanf("%d", &numero);

    if(numero < 1000){
        printf("Numeros impares maiores que %d e menores que 1000:\n", numero);
        for(i = 0; i < 1000; i++){
            if(i > numero && i % 2!= 0){
                printf("%d", i);
            }
        }
    }

}
*/


