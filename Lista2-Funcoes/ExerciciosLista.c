//1.Faça um programa que leia a idade de uma pessoa expressa em anos, meses e dias e em uma
//função mostre-a expressa apenas em dias.

/*#include <stdio.h>

void MostrarExpressaDias(int anos, int meses, int dias) {
    int total_dias = (anos * 365) + (meses * 30) + dias;
    printf("Idade em dias: %d\n", total_dias);
}

int main() {
    int anos, meses, dias;

    printf("Digite sua idade em anos, meses e dias:\n");
    scanf("%d %d %d", &anos, &meses, &dias);

    MostrarExpressaDias(anos, meses, dias);

    return 0;
}*/

//2. Escreva um programa que lê um vetor real de 15 elementos. Leia também um número. A seguir,
//o programa deve mostrar, sem nenhuma casa decimal, cada elemento do vetor multiplicado pelo número lido, em uma função chamada cálculo.

/*#include <stdio.h>

void Calculo(float vetor[], float numero, int tamanho){

    for(int i = 0; i < tamanho; i++){
        printf("%.0f\n", vetor[i] * numero);
    }

}

int main(){

    float vetorReal[15];
    int i;
    float numero;

   for(i = 0; i < 15; i++){
    printf("Elemento %d:", i + 1);
    scanf("%f",&vetorReal[i]);
   }

   printf("Insira um numero:");
   scanf("%f", &numero);

   Calculo(vetorReal, numero, 15);

}*/

//3. Escrever um programa que leia dois números e a seguir realize as operações aritméticas básicas
//(+, -, *, /) sobre estes números. Cada uma das operações deve ser implementada em uma função diferente. 

/*#include <stdio.h>

    soma(int n1, int n2){
        return n1 + n2;

    }

    subtracao(int n1, int n2){
        return n1 - n2;
    }

    multiplicacao(int n1, int n2){
        return n1 * n2;
    }

    divisao(int n1, int n2){
        if(n2 != 0)
            return n1 / n2;
        else
            return 0; // Divisão por zero
    }

int main(){

    int n1, n2;

    printf("Digite um numero:");
    scanf("%d", &n1);

    printf("Digite outro numero:");
    scanf("%d", &n2);

    printf("Soma: %d\n", soma(n1, n2));
    printf("Subtracao: %d\n", subtracao(n1, n2));
    printf("Multiplicacao: %d\n", multiplicacao(n1, n2));
    printf("Divisao: %d\n", divisao(n1, n2));

}*/









