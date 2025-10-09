//7.Ler um vetor com 10 elementos inteiros e um valor inteiro. 
//Usar uma função para contar o número de vezes que o valor aparece no vetor. A função main deve mostrar este valor.
#include <stdio.h>

void ContarNumeros(int vetor[], int numero, int *NumeroAchada){
    int i;
    *NumeroAchada = 0;

    for(i = 0; i < 10; i++){
        if(vetor[i] == numero){
            (*NumeroAchada)++;
        }
    }

}
int main(){
    int vetor[10];
    int numero;
    int NumeroAchado;
    int i;


    printf("Digite 10 valores inteiros:");
    for(i = 0; i < 10; i++){
         scanf("%d", &vetor[i]);
    }

    printf("Digite um numero:");
    scanf("%d", &numero);

    ContarNumeros(vetor, numero, &NumeroAchado);

    printf("O numero %d foi encontrado %d vezes.\n", numero, NumeroAchado);

    return 0;

}