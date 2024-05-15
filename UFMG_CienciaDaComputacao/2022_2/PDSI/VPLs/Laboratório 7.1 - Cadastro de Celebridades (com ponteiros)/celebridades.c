#include <stdio.h>
#include <stdlib.h>
#include "celebridades.h"

    void le_celebridade(celebridade *c){
        fgets(c->nome, 100, stdin);
        char data[12];
        fgets(data, 12, stdin);
        sscanf(data, "%d/%d/%d", &(c->dia_nascimento), &(c->mes_nascimento), &(c->ano_nascimento));
    }
    
    void exibe_celebridade(celebridade *c){
        printf("%s", c->nome);
        printf("%02d de %02d de %04d\n", c->dia_nascimento, c->mes_nascimento, c->ano_nascimento);
    }   

    void adiciona_celebridades(celebridade *c, int n){
        int i;
        for (i = 0; i < n; i++){
            le_celebridade(&c[i]);
        }
    }

    void exibe_celebridades(celebridade *c, int n){
        int i;
        for (i = 0; i < n; i++) {
            exibe_celebridade(&c[i]);
        }
    }