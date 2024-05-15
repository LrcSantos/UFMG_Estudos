#include <stdio.h>
#include "escalar.h"

int main(int argc, char *argv[]) {
    int n, i;
    scanf("%d", &n);
    double U[n], V[n];
    
    for (i = 0; i < n; i++){
        scanf("%lf", &U[i]);     
    }
    for (i = 0; i < n; i++){
        scanf("%lf", &V[i]);     
    }
    
    double escalar = calcula_escalar(U, V, n);
    printf("%.2lf\n", escalar);
    
    return 0;
}