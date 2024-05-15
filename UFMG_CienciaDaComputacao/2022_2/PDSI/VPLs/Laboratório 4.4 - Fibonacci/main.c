#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[]) {
    
    int n = 0;
    int i;
    int lista [100];
    lista[0] = 0;
    lista[1] = 1;
    
    while (n >= 0) {
        printf("Digite um número:\n");
        scanf("%d", &n);
        
        if (n < 0)
            break;
        
        for (i = 2; i < 100; i++){
            lista[i] = lista[i-1] + lista[i-2];
        }
    
    printf("%d\n", lista[n]);
        
    }
    
    return 0;
}