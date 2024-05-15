#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int n, i, k;
    double soma = 0;

    printf("Digite um número inteiro:\n");
    scanf("%d", &n);
    
    double lista1 [n];
    double lista2 [n];
    
    for (i = 0; i < n; i++ ) {
        printf("Digite um número:\n");
        scanf("%lf", &lista1[i]);
    }
    
    for (i = 0; i < n; i++ ) {
        printf("Digite um número:\n");
        scanf("%lf", &lista2[i]);
    }
    
    
    for (k = 0; k < n; k++){
        soma = soma + (lista1[k] * lista2[k]);

    }
    
    printf("%f", soma);
    
    return 0;
}

