#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    
    int n, a;
    printf("Digite um número:\n");
    scanf("%d", &n);
    
    a = fibonacci(n);
    
    printf("%d", a); 
    
    return 0;
}