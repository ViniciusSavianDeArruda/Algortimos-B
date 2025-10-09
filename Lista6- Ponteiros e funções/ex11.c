//11.Ler um vetor de inteiros com 20 elementos. Desenvolver uma função que encontra o maior elemento do vetor e 
//retorne o ponteiro para o maior elemento. A função main deve exibir o maior elemento do vetor.

#include <stdio.h>

int *EncontrarMaiorVetor(int *vetor, int tamanho){
    int i;
    int *maiorElemento = &vetor[0];

    
    for(i = 1; i < tamanho; i++){
       if(vetor[i] > *maiorElemento){
            maiorElemento = &vetor[i];
       }

    }
    
    return maiorElemento;
}


int main(){
    int vetor[20];
    int i;
    int *maior;

    printf("Digite 20 valores do vetor:");
    for(i = 0; i < 20; i++){
        printf("\nElemento %d:", i+1);
        scanf("%d", &vetor[i]);
    }

    maior = EncontrarMaiorVetor(vetor,20);

    printf("Novo maior elemento encontrado: %d\n", *maior);

    return 0;
}