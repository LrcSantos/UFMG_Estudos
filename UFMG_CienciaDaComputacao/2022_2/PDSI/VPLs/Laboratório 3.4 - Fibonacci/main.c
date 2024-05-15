#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int n, a, b, c;
    printf("Digite um número inteiro\n");
    scanf("%d", &n);
    
    int fibonacci;
    int cont;
    
    if (n == 0) {
        fibonacci = 0;
    }
    
    else if (n == 1){
        fibonacci = 1;
    }
    
    else if (n==2){
        fibonacci = 1;
    }
    
        else {
            a = 1;
            b = 1;
            cont = 2;

            while(cont < n) {
                c = a + b;
                a = b;
                b = c;
                cont ++;
                fibonacci = c;
                
            }
        }
    
    printf("%d\n",fibonacci);
    return 0;
}