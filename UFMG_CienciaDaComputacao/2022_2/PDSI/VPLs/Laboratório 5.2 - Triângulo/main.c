#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    
    float a, b, c;
    int x, y;
    printf("Digite três valores:\n");
    scanf("%f%f%f", &a, &b, &c);
    
    x = eh_triangulo(a,b,c);
    y = tipo_triangulo(a,b,c);
    
    if (x == 0){
        printf("Não forma triângulo\n");}
    else
        if (y == 0){
            printf("Escaleno\n");  
        }
    else
        if (y == 1){
            printf("Isósceles\n");  
        }
    else
        if (y == 2){
            printf("Equilátero\n");  
        }
        
    
    return 0;
}