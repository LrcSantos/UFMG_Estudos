#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    // Adicione seu codigo aqui
    
    float b;
    float c;
    
    printf("Digite o valor do primeiro cateto:\n");
    scanf("%f", &b);
    
    printf("Digite o valor do segundo cateto:\n");
    scanf("%f", &c);
    
    double x = pow(b , 2.0) + pow(c, 2.0);
    double a = sqrt(x);
    
    
    printf("%f\n", a);
    
    return 0;
}