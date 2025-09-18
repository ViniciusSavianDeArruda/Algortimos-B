//Aula Algoritmos B - RECURSIVIDADE 
// Recursividade ou recursão é encontrada principalmente na matemática, quando uma função chama a si mesma, ou é usada ela mesma para sua própria definição.

//Exemplo de recursividade em C

/*#include <stdio.h>

// Protótipos das funções
int potencia(int x, int y);
int soma(int n);

int potencia(int x, int y){
    if(y == 0){
        return 1; 
    }
    else if(y > 0){
        return x * potencia(x, y-1);
    }
    return 1; // Caso padrão
}

// Exemplo de recursividade 
// Soma dos n primeiros números inteiros maiores que zero. 
int soma(int n){
    if(n == 0){
        return 0;
    }else if(n > 0){
        return n + soma(n-1);
    }
    return 0; // Caso para números negativos
}*/


// Exemplo: Soma dos n primeiros números inteiros maiores que zero usando recursividade
/*#include <stdio.h>

int soma(int n){
    if(n == 0){     
        return 0;
    }else if(n > 0){
        return n + soma(n-1);
    }
    return 0; // Caso para números negativos
}

int main(){
    int numero, r;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    r = soma(numero);

    printf("A soma dos numeros de 1 ate %d eh: %d\n", numero, r);

    return 0;
}*/


//Conteudo Sobre Ponteiros = Ponteiro é uma variável que contém um endereço da memória. Esse endereço é normalmente a posição de uma outra variável na memória.”
// Fornece meios para ○ Funções modificarem seus argumentos (passagem por referência)
//Implementar alocação dinâmica de memória
//Aumentar a eficiência de certas rotinas

//Operador &
//○ É um operador unário.
//○ Devolve o endereço da memória do operando

//Operador *
//○ É um operador unário.
//○ Devolve o valor da variável localizada no endereço que o segue (devolve o conteúdo apontado).

//Exemplo de uso de ponteiros em C
/*#include <stdio.h>
int main(){
    int x, y, *p1, *p2;
    x = 10;
    p1 = &x;
    y = *p1 *2;
    printf("%d %d %d\n", x, *p1, y);
    p2 = &x;
    *p2 = 30;
    printf("%d %d %d\n", x, *p1, y);

    return 0;

}*/

//Matrizes com ponteiros
//Pode-se acessar os elementos de vetor por meio de:
//○ Indexação: str[2]=‘A’;
//ou
//○ Aritmética de ponteiros: *(ponteiro+2)=‘A’; 



//1. Calcular a soma de 2 vetores de ordem 10.
#include <stdio.h>

int main(){ 
    int vetorA[10], vetorB[10], vetorSoma[10];
    int i;
    int *pA, *pB, *pSoma;
    
    pA = vetorA;
    pB = vetorB;
    pSoma = vetorSoma;

    printf("Digite os 10 numeros do primeiro Vetor A:");
    for(i = 0; i < 10; i++){
        printf("\nIndiceA %d:", i + 1);
        scanf("%d", &vetorA[i]);
    }
    printf("Digite os 10 numeros do segundo Vetor B:");
    for(i = 0; i < 10; i++){
        printf("\nIndiceB %d:\n", i + 1);
        scanf("%d", &vetorB[i]);
    }  
    
	for(i = 0; i < 10; i++){
		*(pSoma + i) = *(pA + i) + *(pB + i);
	}
	
	printf("\nVetor Soma(A + B):\n");
	for(i = 0; i < 10; i++){
		printf("Soma %d = %d\n", i + 1, *(pSoma + i));
	}
	
	return 0;
}

