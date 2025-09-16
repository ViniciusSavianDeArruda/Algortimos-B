//Aula Algoritmos B - RECURSIVIDADE 
// Recursividade ou recursão é encontrada principalmente na matemática, quando uma função chama a si mesma, ou é usada ela mesma para sua própria definição.

// Exemplo: Soma dos n primeiros números inteiros maiores que zero usando recursividade
#include <stdio.h>

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
}


//Conteudo Sobre Ponteiros = Ponteiro é uma variável que contém um endereço da memória. Esse endereço é normalmente a posição de uma outra variável na memória.”
// Fornece meios para ○ Funções modificarem seus argumentos (passagem por referência)
//Implementar alocação dinâmica de memória
//Aumentar a eficiência de certas rotinas

    




