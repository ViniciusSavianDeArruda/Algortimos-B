//6. Ler uma palavra e uma letra qualquer. Usar uma função para mostrar a palavra cortada na primeira posição em que a letra informada for encontrada na palavra. 
//A função main deve exibir a nova string.

#include <stdio.h>

void mostrarPalavraCortada(char letra, char *palavra){
    int i;

    for(i = 0; palavra[i]!='\0'; i++){
        if(palavra[i] == letra){
            palavra[i] = '\0';
        	break;
        }
    }


}

int main(){

    char letra;
    char palavra[100];

    printf("Digite uma letra:");
    scanf(" %c",&letra);

    printf("Digite uma palavra:");
    scanf("%s", palavra);


    mostrarPalavraCortada(letra, palavra);


    printf("Nova palavra cortada :%s\n", palavra);


    return 0;
}