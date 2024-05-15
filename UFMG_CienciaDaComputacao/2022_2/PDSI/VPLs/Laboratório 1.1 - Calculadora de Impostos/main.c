#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float R;
    float F;
    
    printf("Digite o valor da receita da empresa:\n");
    scanf("%f", &R);
    
    printf("Digite o valor dos incentivos fiscais concedidos pelo governo:\n");
    scanf("%f", &F);
    
    double I = (R - F)*0.15;
    
    
    printf("%.02f\n", I);

    return 0;
}