#include "escalar.h"

    double calcula_escalar(double *v1, double *v2, double n){
        int i = 0;
        double soma = 0;
        for (i = 0; i < n; i++){
            soma = soma + (v1[i] * v2[i]);
        }
        return soma;
    }