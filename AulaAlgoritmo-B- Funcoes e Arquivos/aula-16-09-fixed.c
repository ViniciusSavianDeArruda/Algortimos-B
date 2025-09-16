//Aula Algoritmos B - RECURSIVIDADE 
// Recursividade ou recursão é encontrada principalmente na matemática, quando uma função chama a si mesma, ou é usada ela mesma para sua própria definição.

//Exemplo de recursividade em C

#include <stdio.h>

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
}

int main(){
    int base, expoente, r;
    int numero, s;

    // Teste da função potência
    printf("=== CALCULO DE POTENCIA ===\n");
    printf("Digite a base: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &expoente);

    r = potencia(base, expoente);
    printf("%d^%d = %d\n\n", base, expoente, r);

    // Teste da função soma
    printf("=== SOMA DOS N PRIMEIROS NUMEROS ===\n");
    printf("Digite um numero: ");
    scanf("%d", &numero);

    s = soma(numero);
    printf("A soma dos primeiros %d numeros é %d\n", numero, s);

    return 0;
}
