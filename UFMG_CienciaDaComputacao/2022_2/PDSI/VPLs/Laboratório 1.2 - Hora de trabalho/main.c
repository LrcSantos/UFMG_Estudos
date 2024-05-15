#include <stdlib.h>
#include <stdio.h>

int main() {
    // Escreva seu codigo abaixo:
    
    int H;
    float CH;
    
    printf("Digite o valor da quantidade de horas trabalhadas:\n");
    scanf("%d", &H);
    
    printf("Digite o valor do custo de cada hora trabalhada:\n");
    scanf("%f", &CH);
    
    double T = (H * CH)*1.15;
    
    
    printf("%.02f\n", T);
    
    return 0;
}