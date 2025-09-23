//Ponteiros e vetores

#include <stdio.h>
int main(){
    int v[10], *p, i;

    p = &v[0]; // ou p = v;
    printf("Digite 10 numeros:\n");
    for(i = 0; i < 10; i++){
        scanf("%d", &v[i]); // ou scanf("%d", p + i);
    }
    
    printf("\nOs numeros digitados foram:\n");
    for(i = 0; i < 10; i++){
        printf("%d ", v[i]); // ou printf("%d ", *(p + i));
    }
    printf("\n");
    
    return 0;
}

