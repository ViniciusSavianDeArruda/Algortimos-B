//Aula dia 30-09-2025 Algortimos B
//Ponteiros, Funcoes e Vetores

//Passagem para valor com ponteiros
/*#include <stdio.h>
int funcao1 (int x, int y){
	int z;
	x++;
	y = x * 2;
	z = x + y;
return z;
}

//Passagem por referencia
int funcao2 (int *x, int *y){
	int z;
	*x = 20;
	*y = *y + *x;
	z = y;
}
return z;

int main(){
	int a = 5, b = 10, c;
	
	c = funcao1 (a , b);
	
	printf("a = %d b = %d  c = %d", a, b, c);
	
	c = funcao2 (&a, &b);
	
	printf("a = %d b = %d  c = %d", a, b, c);
	
	return 0;
}
*/

//Passagem de vetores para as funcoes é sempre por referencia
/*#include <stdio.h>

void lerVetor(int *p) {
    int i;
    for(i = 0; i < 5; i++) {
        scanf("%d", p + i);
    }
}

void mostrarVetor(int *x) {
    int i;
    for(i = 0; i < 5; i++) {
        printf("%d\t", *(x + i));
    }
    printf("\n");  
}

void somarVetores(int *v1, int *v2, int *v3) {
    int i;
    for(i = 0; i < 5; i++) {
        *(v3 + i) = *(v1 + i) + *(v2 + i);
    }
}

int main() {
    int v[5], t[5], s[5];

    printf("Digite os dados do primeiro vetor:\n");
    lerVetor(v);

    printf("Digite os dados do segundo vetor:\n");
    lerVetor(t);

    printf("\nPrimeiro vetor:\n");
    mostrarVetor(v);

    printf("Segundo vetor:\n");
    mostrarVetor(t);

    somarVetores(v, t, s);

    printf("Vetor soma:\n");
    mostrarVetor(s);

    return 0;
}*/




#include <stdio.h>

int contar(char *p, char l){
	int qtde = 0;
	
	for( ; *p!='\0'; p++) // *p
		if(*p == l){
			qtde ++;
			*p = '*';
}
	return qtde;
}

int main(){
	char palavra [30], letra;
	int q;
	
	scanf("%s", palavra);
	fflush(stdin);
	scanf("%c", &letra);
	
	q = contar(palavra, letra);
	
	printf("qtde = %d\n", q);
	puts(palavra);
	
	return 0;
}









