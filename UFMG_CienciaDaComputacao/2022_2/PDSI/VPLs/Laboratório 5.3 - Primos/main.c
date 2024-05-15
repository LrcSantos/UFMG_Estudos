#include <stdio.h>
#include "func.h"

int main(int argc, char *argv[]) {
    int a = 0; 
    int n;
    
    while (a >= 0){
        printf("Digite um número:\n");
        scanf("%d", &n);
        a = n;
        if (a < 0){
            break;
        }
        printf("%d\n", soma_primos(n));
    }

    return 0;
}