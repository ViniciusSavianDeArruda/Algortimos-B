//2.Ler uma string e chamar uma função para contar quantos caracteres possui. A main deve exibir a quantidade de caracteres.

#include <stdio.h>

int ContarCaracteres(char *p){
	int i = 0;
	
	for(i = 0; p[i] !='\0'; i++){
}
	return i;
}

int main(){
	char palavra[50];
	int tamanho;
	
	printf("Digite uma palavra:");
	scanf("%49s",palavra);
	
	tamanho = ContarCaracteres(palavra);
	
	printf("A palavra tem %d caracteres.\n", tamanho);
	
	return 0;
}