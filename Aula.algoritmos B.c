//Aula Algorimtmos B & Exercicios 12/08/2025

/*Conjuntos Heterogêneos constituem tipos de dados definidos pelo usuário:
Estruturas (struct)
Uniões (union)
Enumeração (enum)
*/

// Exemplo de uso de struct para armazenar dados de uma pessoa e seu endereço uma dentro de outra
// A struct pode conter outras structs como membros, formando uma estrutura aninhada.
/*#include <stdio.h>
struct endereco{
    char rua[40];
    int nro;
    char complemento[20];
    char CEP[10];
    char cidade[30];
    char estado[3];

};

struct pessoa{
    char nome[40];
    struct endereco e;
};

int main(){
    struct pessoa a;
    
    printf("Informe o nome: ");
    fgets(a.nome,60,stdin);

    printf("Informe a rua: ");
    fgets(a.e.rua,40,stdin);

    printf("Informe o numero: ");
    scanf("%d",&a.e.nro);

    printf("Informe o complemento: ");
    fgets(a.e.complemento,20,stdin);

    printf("Informe o CEP: ");
    fgets(a.e.CEP,10,stdin);

    printf("Informe a cidade: ");
    fgets(a.e.cidade,30,stdin);

    printf("Informe o estado: ");
    fgets(a.e.estado,3,stdin);


    puts("\n\nDados informados:\n");

    puts(a.nome);
    puts(a.e.rua);
    printf("numero%d\n",a.e.nro);
    puts(a.e.complemento);
    puts(a.e.CEP);
    puts(a.e.cidade);
    puts(a.e.estado);

    return 0;

}*/

//Union é uma estrutura de dados que permite armazenar diferentes tipos de dados na mesma posição de memória, economizando espaço.
//Ele permite que diferentes tipos de dados compartilhem o mesmo espaço de memória, mas apenas um deles pode ser usado por vez.]
//Posicao de memoria é compartilhada entre os membros da união, economizando espaço, mas limitando o uso a um membro por vez.

/*#include <stdio.h>
#define Pi 3.14159
union angulo
        {
        float graus;
        float radianos;
        };
void main(void) {
   union angulo ang;
   float auxGrau;
   char op;
   printf("\nNumeros em graus (G) ou radianos (R)? ");
   scanf("%c",&op);
   printf("Digite o angulo: ");
   scanf("%f",&auxGrau);
   if (op == 'G') {
      printf("Angulo digitado em graus %f\n", auxGrau);
      ang.radianos = auxGrau/180*Pi;
      printf("\nAngulo em radianos: %f\n",ang.radianos);
   } else if (op == 'R') {
             printf("Angulo digitado em radianos %f\n", auxGrau);
             ang.graus = auxGrau*180/Pi;
             printf("\nAngulo em graus: %f\n",ang.graus);
          }
          else printf("\nEntrada invalida!!\n");
}*/




//Enumeração (enum) é um tipo de dado definido pelo usuário que consiste em um conjunto de constantes nomeadas, chamadas enumeradores.
//Cada enumerador é associado a um valor inteiro, começando do zero por padrão, mas pode ser atribuído um valor específico a qualquer enumerador.
//Enumerações são úteis para representar um conjunto fixo de valores relacionados, melhorando a legibilidade e a manutenção do código.
//enu trabalha com constantes
/*#include <stdio.h>

int main (void) {
     enum estacoes {primavera, verao, outono, inverno };
     enum estacoes est_ano;

     est_ano = inverno;
     printf ("%d",est_ano);
     if (est_ano==2){
                     printf("outono");
                     }
     if (outono>verao){
        printf ("Frio");
     } else prinft("Quente");

     return 0;
}*/



//Outras funcoes da linguagem C
/*
atoi - converte string para int
atof - converte string para float
atoia - converte string para int (long)
atof - converte string para float (double)


*/


//Typedef é uma palavra-chave em C que permite criar um novo nome (alias) para um tipo de dado existente.
//nao é uma boa pratica usar typedef para tipos simples como int, float, char, etc., pois isso pode reduzir a clareza do código.
//É mais comum e recomendado usar typedef para tipos de dados compostos, como structs, unions e nums
//e enums, onde a criação de um alias pode melhorar a legibilidade e facilitar a manutenção do código.
//na declaracao da variavel, o nome do tipo definido com typedef é usado como qualquer outro tipo de dado.