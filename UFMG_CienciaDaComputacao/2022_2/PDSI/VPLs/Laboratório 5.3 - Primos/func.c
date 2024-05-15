#include "func.h"

    int eh_primo (int n){
        int resultado = 0;
        int q, i, b;

        if (n != 0 && n != 1){
            for (i = 2; i <= n / 2; i++) {
                if (n % i == 0) {
                    resultado++;
                    break;
                }
            }
 
            if (resultado == 0)
                q = 1;
            else 
                q =0;
        }
        else
            q = 0;
        return q;
    }
    
    int soma_primos (int x){
        int soma = 0, i = 0, j = 0;
        int a;
        
        while (i < x){
            a = eh_primo(j);
            j++;
            if (a == 1){
                soma = soma + (j - 1);
                i++;
            }
        }
        return soma;
    }