#include <stdio.h>

int main(int argc, char *argv[]) {

    int i;
    int numeros [10];
    
    for (i = 0; i < 10; i++ ) {
        printf("Digite um número:\n");
        scanf("%d", &numeros[i]);
    }
    
    for (i = 9; i >= 0; i-- ) {
        printf("%d ", numeros[i]);
    }
    
    return 0;
}