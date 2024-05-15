#include "func.h"

    int subarranjo_maximo(int *A, int n){
        int cont = 1;
        int i, k, j, l, soma1 = 0, soma2 = 0; 
        int soma_maior = 0;

        for (i = 0; i < n; i++){
            soma1 = soma1 + A[i];

            if (soma1 >= soma_maior){
                soma_maior = soma1;
            }
            if (-A[i] > soma1){
                soma1 = 0;
            }
        }
        for (j = n-1; j >= 0; j--){
            soma2 = soma2 + A[j];
            
            if (soma2 >= soma_maior){
                soma_maior = soma2;
            }
            if (-A[j] > soma2){
                soma2 = 0;
            }
        }
        return soma_maior;
    }