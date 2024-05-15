#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int a, b, c;
    printf("Digite três números inteiros:\n");
    scanf("%d%d%d", &a, &b, &c);
    int r = a % b;
    
    while(r != 0) {
        a = b;
        b = r;
        r = a % b; 
    }

    int r1 = b % c;
    
    while(r1 != 0) {
        b = c;
        c = r1;
        r1 = b % c;
    }
    
    printf("%d", c);
    
    return 0;
}