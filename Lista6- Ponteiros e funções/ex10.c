//10.Faça um programa que lê duas matrizes 3x3 e efetua a soma das matrizes usando funções. Use ponteiros para manipular as matrizes nas funções.

#include <stdio.h>

void SomarMatrizes(int *matriz1, int *matriz2, int *soma){
    int i, j;

    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){

            //calculo soma das duas matrizes
            // soma[i][j] = matriz1[i][j] + matriz2[i][j]
            *(soma + i*3 + j) = *(matriz1 + i*3 + j) + *(matriz2 + i*3 + j);
        }
    }
        
}
int main(){
    int matriz1[3][3], matriz2[3][3], soma[3][3];
    int i; //percorrer as linhas
    int j;//percorrer as culunas
    
    printf("Insira os elementos da primeira matriz 3x3:");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("\nElemento %d %d:",i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("Insira os elementos da segunda matriz 3x3:");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("\nElemento %d %d:",i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
    
    SomarMatrizes(&matriz1[0][0], &matriz2[0][0], &soma[0][0]);

    //Mostrar resultado da soma das matrizes
    printf("\nMatriz soma:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%d ", soma[i][j]);
        }

        printf("\n");
    }

    return 0;
}