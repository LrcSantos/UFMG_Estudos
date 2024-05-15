#include <stdio.h>

int main(int argc, char *argv[]) {

    int n;
    int soma = 0;
    printf("Digite um número inteiro positivo:\n");
    scanf("%d", &n);
    
    while (n % 10 != 0) {
        
        soma = soma + n % 10;
        n = n / 10;
        
    }
    
    printf("%d",soma);
    
    return 0;
}