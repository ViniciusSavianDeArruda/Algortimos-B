//1.Ler uma string e desenvolver uma função para escreve-la verticalmente na tela.
#include <stdio.h>

void palavraVertifical(char *p){
	
	for(  ; *p !='\0'; p++){
		printf("%c\n",*p);
	}
}

int main(){
	char palavra[30];

	printf("Digite uma palavra:");
	scanf("%29s", palavra);
	
	palavraVertifical(palavra);
	
}