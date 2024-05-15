#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    int n, i;
    scanf("%d", &n);
    double *U = aloca_vetor(n); 
    double *V = aloca_vetor(n);
    
    for (i = 0; i < n; i++){
        scanf("%lf", &U[i]);     
    }
    for (i = 0; i < n; i++){
        scanf("%lf", &V[i]);     
    }
    
    double escalar = calcula_escalar(U, V, n);
    printf("%.6lf\n", escalar);
    
    libera_vetor(U);
    libera_vetor(V);
    
    return 0;
}