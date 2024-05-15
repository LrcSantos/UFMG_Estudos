#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    
    int n, a, i;

    //printf("Digite um número:\n");
    scanf("%d", &n);
    
    int A[n];   
    
    for (i = 0; i < n; i++){
        //printf("Digite um número para a lista:\n");
        scanf("%d", &a);
        A[i] = a;
    }
    
    int q = subarranjo_maximo(A, n);
    printf("%d", q);
    

    return 0;
}