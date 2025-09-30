//1.Ler uma string e desenvolver uma função para escreve-la verticalmente na tela.
#include <stdio.h>

void palavraVertifical(char *p){
	int i;
	
	for(i = 0; p[i] !='\0'; i++){
		printf("%c\n",p[i]);
	}
}

int main(){
	char palavra[30];

	printf("Digite uma palavra:");
	scanf("%s", palavra);
	
	palavraVertifical(palavra);
	
}