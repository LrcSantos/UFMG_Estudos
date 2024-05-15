#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    
    int n, a, i;


    scanf("%d", &n);
    
    int *A = aloca_vetor(n);
    
    for (i = 0; i < n; i++){

        scanf("%d", &a);
        *(A+i) = a;
    }
    
    int q = subarranjo_maximo(A, n);
    printf("%d", q);
    
    libera_vetor(A);
    

    return 0;
}
