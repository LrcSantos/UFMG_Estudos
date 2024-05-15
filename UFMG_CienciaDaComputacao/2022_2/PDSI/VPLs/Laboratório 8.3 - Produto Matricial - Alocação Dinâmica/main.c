#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {

    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);

    double **U = aloca_matriz(n, m);
    le_matriz(U, n, m);

    double **V = aloca_matriz(m, n);
    le_matriz(V, m, n);

    
    double **P = aloca_matriz(n, m);
    P = produto_matricial(U, V, n, m);
    
    exibe_matriz(produto_matricial(U, V, n, m), n, n);

    return 0;
}