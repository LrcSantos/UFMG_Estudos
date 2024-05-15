#include <stdio.h>
#include <stdlib.h>
#include "celebridades.h"

    Celebridade le_celebridade(int i){
    
        fgets(c[i].nome, 100, stdin);
        fgets(c[i].data, 100, stdin);
    }
    
    void exibe_celebridade(Celebridade c){
        int i, k;
        for (i = 0; c.nome[i] != '\0'; i++){
            printf("%c", c.nome[i]);
        }
        printf("%c%c de %c%c de %c%c%c%c\n", c.data[0], c.data[1], c.data[3], c.data[4], c.data[6], c.data[7], c.data[8], c.data[9]);
    }
    
    void adiciona_celebridades(Celebridade *cs, int n){
        int i;
        for (i = 0; i < n; i++){
            le_celebridade(i);
        }
    }
    
    void exibe_celebridades(Celebridade *cs, int n){
        int i;
        for (i = 0; i < n; i++){
            exibe_celebridade(c[i]);
        }
    }