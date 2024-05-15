#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int a, b;
    
    printf ("Digite a velocidade máxima da via:\n");
    scanf ("%d", &a);
  
    printf ("Digite a velocidade registrada pelo radar:\n");
    scanf ("%d", &b);
    
    if (b <= a)
    {
        printf("Entrada: %d %d\n", a, b);
        printf("Saída: Sem Infração");
    }
    
    else if (b <= (a + 0.2*a))
    {
        printf("Entrada: %d %d\n", a, b);
        printf("Saída: Infração Média");
    }
    
    else if (b <= (a + 0.5*a))
    {
        printf("Entrada: %d %d\n", a, b);
        printf("Saída: Infração Grave");
    }
        else
        {
            printf("Entrada: %d %d\n", a, b);
            printf("Saída: Infração Gravíssima");
        } 
    
    return 0;
}