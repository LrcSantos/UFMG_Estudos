#include <stdbool.h>
#include "palindromo.h"

    int palindromo(char *palavra, int inicio, int fim){
        
        if (inicio >= fim){
            return true;
        }
        
        if (palavra[inicio] != palavra[fim]){
            return false;
        }
        
        return palindromo(palavra, inicio + 1, fim - 1);   
    }