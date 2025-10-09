//Faça um programa que lê uma string e um caractere e chama uma função para contar quantas vezes o caractere ocorre na string. 
//Use ponteiros para receber e manipular a string na função.

#include <stdio.h>

void ContarCatacteres(char palavra[], char caracter, int *achado){
    int i;

    for(i = 0; palavra[i] !='\0';i++){
        if(palavra[i] == caracter){
            (*achado)++;
        }
    }

}
int main(){
    char palavra[100];
    char caracter;
    int achado = 0;

    printf("Digite uma palavra qualquer:");
    scanf("%s", palavra);
    
    printf("Digite um caracter:");
    scanf(" %c", &caracter);

    ContarCatacteres(palavra, caracter, &achado);

   printf("O caractere '%c' foi encontrado %d vezes.\n", caracter, achado);

    return 0;

}