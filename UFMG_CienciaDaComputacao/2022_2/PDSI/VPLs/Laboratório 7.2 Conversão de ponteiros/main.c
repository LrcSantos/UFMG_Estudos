
#include <stdio.h>

#include "converte.h"

int main(int argc, char *argv[]) {
    double numero;
    scanf("%lf", &numero);
    int* num_int = converte_para_inteiro(&numero);
    float* num_flt = converte_para_float(&numero);
    char* num_chr = converte_para_char(&numero);

    printf("%d\n", *num_int);
    printf("%f\n", *num_flt);
    printf("%c\n", *num_chr);
    
    return 0;
}
