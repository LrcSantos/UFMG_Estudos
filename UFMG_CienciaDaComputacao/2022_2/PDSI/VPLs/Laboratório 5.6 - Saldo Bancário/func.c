#include "func.h"
#include <stdio.h>

double saldo;

    double inicia_saldo(){
        double saldo = 0.00;
        return saldo;
    }
    
    double deposita_valor(double deposito){
        saldo = saldo + deposito;
        return saldo;
    }
    
    double resgata_valor(double retirada){
        saldo = saldo - retirada;
        return saldo;
    }
    
    double retorna_valor(){
        return saldo;
    }
    
    void le_entrada(int n){
        if (n == 1){
            printf("%.2lf\n", retorna_valor());
        }
        else if (n == 2){
            double v;
            scanf("%lf", &v);
            saldo = deposita_valor(v);
        }
        else if (n == 3){
            double v2;
            scanf("%lf", &v2);
            saldo = resgata_valor(v2);
        }
    }