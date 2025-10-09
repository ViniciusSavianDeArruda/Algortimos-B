//Faça um programa que lê dois vetores de inteiros com 10 elementos e chama funções para executar as seguintes operações:

//a Soma de vetores
//b Subtração de vetores
//c Produto escalar dos vetores
//Use ponteiros para manipular os vetores nas funções.

#include <stdio.h>

// Função para somar os vetores usando ponteiros
void SomaVetores(int *vetor1, int *vetor2, int *soma){
    int i;
    *soma = 0;
    for(i = 0; i < 10; i++){
        *soma += *(vetor1 + i) + *(vetor2 + i);
    }
}
// Função para subtrair os vetores usando ponteiros
void SubtracaoVetores(int *vetor1, int *vetor2, int *subtracao){
    int i;
    *subtracao = 0;
    for(i = 0; i < 10; i++){
        *subtracao += *(vetor1 + i) - *(vetor2 + i);
    }
}
// Função para calcular o produto escalar usando ponteiros
void ProdutoEscalar(int *vetor1, int *vetor2, int *resultado){
    int i;
    *resultado = 0;
    for(i = 0; i < 10; i++){
        *resultado += *(vetor1 + i) * *(vetor2 + i);
    }
}
int main(){
    int vetor1[10], vetor2[10];
    int soma, subtracao, prodEsc;
    int i;

    // Leitura dos vetores
    for(i = 0; i < 10; i++){
        printf("Digite o elemento %d do primeiro vetor: ", i);
        scanf("%d", vetor1 + i);
    }

    for(i = 0; i < 10; i++){
        printf("Digite o elemento %d do segundo vetor: ", i);
        scanf("%d", vetor2 + i);
    }

    // Chamadas das funções
    SomaVetores(vetor1, vetor2, &soma);
    SubtracaoVetores(vetor1, vetor2, &subtracao);
    ProdutoEscalar(vetor1, vetor2, &prodEsc);

    // Resultados
    printf("\nA soma dos vetores é: %d\n", soma);
    printf("A subtracao dos vetores é: %d\n", subtracao);
    printf("O produto escalar dos vetores é: %d\n", prodEsc);

    return 0;
}
