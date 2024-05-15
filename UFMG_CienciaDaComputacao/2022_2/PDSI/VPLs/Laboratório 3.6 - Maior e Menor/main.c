#include <stdio.h>

int main(int argc, char *argv[]) {

    int n, a, b, c, d;
    
    printf("Digite um inteiro positivo:\n");
    scanf("%d", &n);
    
    printf("Digite um número:\n");
    scanf("%d", &a);
    
    d = a;
    b = d;
    
    for (n; n > 1; n--){
        
        printf("Digite um número:\n");
        scanf("%d", &b);
        c = b;
        
        if (b >= a)
            a = b;
            
        if (c <= b)
            b = c;
        
        if (d <= b)
            b = d;
    }

    printf("Menor: %d\n", b);    
    printf("Maior: %d\n", a);
    
    return 0;
}