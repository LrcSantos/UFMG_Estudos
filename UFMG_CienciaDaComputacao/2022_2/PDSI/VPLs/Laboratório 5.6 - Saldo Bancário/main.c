#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    
    int n; 
    int operacoes;
    int i = 0;
    double valor = inicia_saldo();
    scanf("%d", &operacoes);

    while (i < operacoes){
        //printf("Digite um número:\n");
        scanf("%d", &n);
        i++;
    le_entrada(n);
    }
    return 0;
}
