#include "func.h"

    int arranjo_posicoes_valido(int *A, int n){
        int cont = 1;
        int i, k;
        for (i = 0; i < n; i++){
            if (A[i] >= n || A[i] < 0)
                cont = 0;
            for(k = 0;k <= i-1; k++){
                if(A[i] == A[k]){
                   cont = 0;
                }
            }
        }

        return cont;
    }