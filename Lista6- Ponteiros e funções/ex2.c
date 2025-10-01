#include <stdio.h>

int ContarCaracteres(char *p) {
    int i = 0;

    for (; *p != '\0'; p++) {
        i++;
    }
    return i;
}
int main() {
    char palavra[50];
    int tamanho;

    printf("Digite uma palavra: ");
    scanf("%49s", palavra);

    tamanho = ContarCaracteres(palavra);

    printf("A palavra tem %d caracteres.\n", tamanho);

    return 0;
}
