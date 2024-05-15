#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int n;
    
    printf("Digite um número:\n");
    scanf("%d", &n);
    
    long long int a = 1;
    
    for ( int i = 1; i <= n; i++){
        
        a = a * i;
    }
    
    printf("%lld", a);
    return 0;
    return 0;
}