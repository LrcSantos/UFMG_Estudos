#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {

    int a;
    int b;
    
    printf("Digite um valor boleano:\n");
    scanf("%d", &a);
    
    printf("Digite outro valor boleano:\n");
    scanf("%d", &b);
    
    int c = a & b;
    int d = a | b;
    int e = a ^ b;
    
    printf("AND: %d OR: %d XOR: %d\n", c, d, e);

	
	return 0;
}
