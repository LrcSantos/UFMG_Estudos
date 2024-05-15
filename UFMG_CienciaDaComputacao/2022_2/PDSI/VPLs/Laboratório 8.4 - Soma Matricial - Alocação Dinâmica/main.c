#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    double **U = aloca_matriz(n, m);
    le_matriz(U, n, m);

    double **V = aloca_matriz(n, m);
    le_matriz(V, n, m);

    
    double **S = aloca_matriz(n, m);
    S = soma_matricial(U, V, n, m);
    
    exibe_matriz(soma_matricial(U, V, n, m), n, m);

    return 0;
}
