//5.Ler duas palavras e usar uma função para compará-las. A main deve informar se as palavras são iguais ou diferentes
#include <stdio.h>

void CompararPalavras(char *p1, char *p2){
	int i;

	for(i = 0; p1[i] !='\0' && p2[i] !='\0'; i++){
		if(p1[i] != p2[i]){
			printf("As palavras sao diferentes\n");
			return;
		}
	}
	
	if(p1[i] != '\0' || p2[i] != '\0'){
			printf("As palavras sao diferentes\n");
		}else{
			printf("As palavras sao iguais\n");
	}
}

int main(){
	char palavra1[20];
	char palavra2[20];
	
	printf("Digite a primeira palavra:");
	scanf("%s", palavra1);	
	
	printf("Digite a segunda palavra:");
	scanf("%s", palavra2);	
	
	
	CompararPalavras(palavra1, palavra2);
	
	return 0;
}