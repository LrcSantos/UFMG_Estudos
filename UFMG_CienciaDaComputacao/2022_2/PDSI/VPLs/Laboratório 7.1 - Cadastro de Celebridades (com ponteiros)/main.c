
#include <stdio.h>

#include "celebridades.h"

int main(int argc, char *argv[]) {
    int n;
    scanf("%d\n", &n);
    celebridade vetor[n];
    adiciona_celebridades(&vetor[0], n);
    exibe_celebridades(&vetor[0], n);
    return 0;
}
