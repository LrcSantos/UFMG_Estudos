#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raiz.h"

int main(int argc, char *argv[]) {
    double n;
    scanf("%lf", &n);
    double r = raiz(n, n);
    printf("%0.2lf", r);
    return 0;
}

