#include <stdio.h>

int main(int argc, char *argv[]) {

    int n;
    int i;

    printf("Digite um número inteiro:\n");
    scanf("%d", &n);
    
    int numeros [n];
    
    for (i = 0; i < n; i++ ) {
        printf("Digite um número:\n");
        scanf("%d", &numeros[i]);
    }
    
    for (i = 0; i < n; i++ ) {
        printf("%d ", numeros[i]);
    }
    
    return 0;
}