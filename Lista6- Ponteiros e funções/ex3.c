//3.Ler uma string e chamar uma função para inverte-la dentro da mesma string. Mostrar a string invertida.
#include <stdio.h>
#include <string.h>

void InverterString(char *p) {
    char *inicio = p;                  
    char *fim = p + strlen(p) - 1;   
    
    while (inicio < fim) {
        char temp = *inicio;   // troca
        *inicio = *fim;
        *fim = temp;
        
        inicio++;
        fim--;
    }
}

int main() {
    char palavra[30];
    
    printf("Digite uma palavra: ");
    scanf("%29s", palavra); 
    
    InverterString(palavra);
    
    printf("String invertida: %s\n", palavra);
    
    return 0;
}
