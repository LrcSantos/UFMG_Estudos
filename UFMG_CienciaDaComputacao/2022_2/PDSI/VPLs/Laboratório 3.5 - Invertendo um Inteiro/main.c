#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int n, a;
    int cont = 0;
    printf("Digite um número inteiro positivo:\n");
    scanf("%d", &n);
    
    a = n;

    while (n % 10 != 0) {
        cont++;
        n = n / 10;
    }
    
    int soma = 0;
    
    while (a % 10 != 0) {
        int resto = a % 10;
        a = a / 10;
        cont--;
        soma = soma + resto * pow(10,cont);
    }
    
    printf("Valor invertido: %d", soma);
    
    return 0;
}