//4.Escrever um programa que leia uma palavra qualquer e use uma função para verificar se esta palavra é um palíndromo. 
#include <stdio.h>
#include <string.h>

void VerificarPalindromo(char *p) {
    int tamanho = strlen(p);
    int i;

    for(i = 0; i < tamanho / 2; i++) {
        if(p[i] != p[tamanho - 1 - i]) {
            printf("Nao é palindromo\n");
            return;
        }
    }

    printf("E palindromo\n");
}

int main() {
    char palavra[20];

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    VerificarPalindromo(palavra);

    return 0;
}
