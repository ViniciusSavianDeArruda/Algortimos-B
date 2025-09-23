//Exercicio
/*#include <stdio.h>

int m[6][6];

void lerLinha(){
    int j;

    printf("Insira os elementos da 1 linha:\n");

    for(j = 0; j < 6; j++){
        scanf("%d", &m[0][j]);
    }

}

void preencherMatriz(){
    int i, j ;
    
    for(i = 1; i < 6; i++){
        for(j = 0; j < 6; j++){
            m[i][j] = m[0][j] * (i + 1);
        }
    }
}

void MostrarMatriz(){

    int i, j;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(){
    lerLinha();
    preencherMatriz();
    MostrarMatriz();
    
    return 0;
}*/


//Funções recursivas são funções que se chamam a si mesmas e são usadas para 
//resolver problemas que podem ser divididos em subproblemas menores do mesmo tipo.

//Exemplo de função recursiva para calcular o fatorial de um número:
/*#include <stdio.h>

unsigned int fatorial(unsigned  int n){
    int i; 
    unsigned  int fat = 1;

    for(i = 1; i <= n; i++){
        fat = fat * i;
    }

    return fat;
}


int main(){
    unsigned int d;
    
    scanf("%i", &d);

    printf("Fatorial de %d = %d", d, fatorial(d));
}*/







