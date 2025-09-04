/*Desenvolva um algoritmo, para ler o salário bruto (R$) de um
funcionário e calcular:
○ o desconto (R$) do INSS;
○ a contribuição (R$) para o IRPF;
○ o valor do salário em dólares.
● Utilize funções para implementar o algoritmo e considere as
seguintes tabelas do INSS e do IRPF:*/

/*#include <stdio.h>

float INSS(float s){
    if (s <= 1302){
        return s * 0.075;
    } else if(s <= 2571.29){
        return s * 0.09;
    } else if (s <= 3856.94){
        return s * 0.12;
    } else{
        return s * 0.14;
    }
}

float IRPF(float s){
    if(s <= 2112){
        return 0;
    } else if(s <= 2826.65){
        return s * 0.075;
    } else if(s <= 3751.05){
        return s * 0.15;
    } else if(s <= 4664.68){
        return s * 0.225;
    } else {
        return s * 0.275;
    }
}

float CalcularDolar(float s, float d){
    return s / d;
}

int main(){
    float salarioB, descINSS, descIRPF, salarioDolar, dolar, salarioLiquido;

    printf("Informe o salario bruto (R$): ");
    scanf("%f", &salarioB);

    descINSS = INSS(salarioB);
    salarioLiquido = salarioB - descINSS;  
    descIRPF = IRPF(salarioLiquido);       
    
    printf("Salario Bruto: R$ %.2f\n", salarioB);
    printf("Desconto INSS: R$ %.2f\n", descINSS);
    printf("Contribuicao IRPF: R$ %.2f\n", descIRPF);
    printf("Salario Liquido: R$ %.2f\n", salarioLiquido - descIRPF);
    
    printf("Informe a cotacao do dolar (R$): ");
    scanf("%f", &dolar);

    salarioDolar = CalcularDolar(salarioB, dolar);
    printf("Salario em dolar = U$ %.2f\n", salarioDolar);

    return 0;
}*/



//EXEMPLO 4
/*Ler um vetor de 10 elementos e mostrar todos os elementos
pares digitados e sua posição no vetor.
○ Para desenvolver esta solução, vamos utilizar o que
chamamos de variável global.
*/

//Variável Global é aquela variável criada fora de qualquer função. Seu escopo (tempo de vida dentro do programa) é todo o programa,
//podendo ser acessada/alterada em qualquer função. 


/*#include <stdio.h>

int vetor[10]; // Variável global

void mostrarPares(){
    int i;


    printf("Elementos pares no vetor:\n");
    for(i = 0; i < 10; i++){
        if(vetor[i] % 2 == 0){
            printf("%d na posicao %d\n", vetor[i], i);
        }
    }
}



int main(){
    int i;

    printf("Digite 10 numeros:\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &vetor[i]);
    }

    mostrarPares();

    return 0;


}*/



/*EXEMPLO 5
Ler um número inteiro e usar uma função que retorna 0, se o
número é par, ou 1, se o número é impar.
*/

/*#include <stdio.h>

int par(int n){
    return n % 2 == 0;  // retorna 1 se par, 0 se ímpar
}

int main(){
    int x;

    printf("Digite um numero inteiro: ");
    scanf("%d", &x);

    if(par(x)){
        printf("O numero é par\n");
    } else {
        printf("O numero é impar\n");
    }

    return 0;
}*/







