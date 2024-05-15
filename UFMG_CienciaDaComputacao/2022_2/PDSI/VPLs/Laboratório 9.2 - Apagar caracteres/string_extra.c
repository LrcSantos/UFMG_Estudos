#include "string_extra.h"
#include <string.h>
    
    void deslocamento(char *str, int i){
        
        if (i >= strlen(str)){
            return;
        }
        str[i] = str[i + 1];
        deslocamento(str, i + 1);
    }
    
    void aux(char *str, char c, int i){
        
        if (i >= strlen(str)){
            return;
        }
    
        if (str[i] == c){
            deslocamento(str, i);
            aux(str, c, i);
        } 
        
        else{
            aux(str, c, i + 1);
        }
    }
    
    void apaga_caractere(char *str, char c){
        
        aux(str, c, 0);
    }