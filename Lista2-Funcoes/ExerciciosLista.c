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







