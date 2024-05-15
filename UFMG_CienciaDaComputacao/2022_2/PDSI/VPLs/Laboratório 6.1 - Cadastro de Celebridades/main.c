#include <stdio.h>
#include "celebridades.h"

int main(int argc, char *argv[]) {
    Celebridade vetor[100];
    
    int n;
    scanf("%d\n", &n);
    
    adiciona_celebridades(vetor, n);
    exibe_celebridades(vetor, n);
    
    return 0;
}
