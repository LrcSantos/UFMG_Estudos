#include <stdio.h>
#include <math.h>
#include "quadrado.h"

    Linha le_linha(){
        int i;
        for (i = 0; i < 4; i++){
            scanf("%d", &l[i].i.x); 
            scanf("%d", &l[i].i.y); 
            scanf("%d", &l[i].f.x); 
            scanf("%d", &l[i].f.y);
        }
    }
    
    Quadrado le_quadrado(){
        le_linha();
    }
    
    float pitagoras(int a, int b){
        float h;
        h = sqrt((pow(a,2) + pow(b,2)));
        
        return(h);
    }
    
    void exibe_perimetro(){
        int i;
        float soma = 0;
        int soma_total = 0;
        for (i = 0; i < 4; i++){
            soma = soma +  pitagoras((l[i].f.y - l[i].i.y), (l[i].f.x - l[i].i.x));
        }

        printf("%d", (int)soma);
    }