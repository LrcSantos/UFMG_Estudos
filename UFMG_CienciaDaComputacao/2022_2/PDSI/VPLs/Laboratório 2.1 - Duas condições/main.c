#include <stdio.h>

int main(int argc, char *argv[]) {
    
        int n;
    printf("Digite um número\n");
    scanf("%d", &n);
    
    if (n < 50)
    {
        printf("0");
    }
    
    else
    {
        printf("1");
    }
    
    return 0;
}