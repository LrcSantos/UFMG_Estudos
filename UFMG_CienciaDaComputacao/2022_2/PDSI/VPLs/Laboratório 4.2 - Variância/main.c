#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int n, i;
    double soma = 0;

    printf("Digite um número inteiro:\n");
    scanf("%d", &n);
    
    int numeros [n];
    
    for (i = 0; i < n; i++ ) {
        printf("Digite um número:\n");
        scanf("%d", &numeros[i]);
    }

    for (i = 0; i < n; i++ ) {
        soma = soma + numeros[i];
    }   
    
    double media = soma / n;
    double var; 
    double soma_var = 0;

    for (i = 0; i < n; i++ ) {
        var = pow((numeros[i] - media), 2);
        soma_var = soma_var + var;
    }   
    
    long double var_final = soma_var / n;

    printf("%Lf", var_final);
    
    return 0;
}

