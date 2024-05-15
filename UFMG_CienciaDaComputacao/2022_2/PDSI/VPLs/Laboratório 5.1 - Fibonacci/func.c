#include "func.h"
    int fibonacci(int n){

    int i, fibo;
    int lista [100];
    lista[0] = 0;
    lista[1] = 1;
    
        
    for (i = 2; i < 100; i++){
        lista[i] = lista[i-1] + lista[i-2];
    }
    
    
    fibo = lista[n];

    
    return fibo;
}