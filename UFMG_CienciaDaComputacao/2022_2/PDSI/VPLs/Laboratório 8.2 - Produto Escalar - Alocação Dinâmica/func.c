#include "func.h"
#include <stdlib.h>

    double* aloca_vetor(double n){
        double *p;
        p = (double*) malloc(n*sizeof(double));
        
        return p;
    }

    double calcula_escalar(double *vetor1, double *vetor2, double n){
        int i = 0;
        double soma = 0;
        for (i = 0; i < n; i++){
            soma = soma + (vetor1[i] * vetor2[i]);
        }
        return soma;
    }
    
    void libera_vetor(double *vetor){
        free(vetor);
    }