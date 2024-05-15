#include "raiz.h"

    double raiz(double n, double palpite){
        
        double est = (palpite * palpite);
        
        if (absoluto(est - n) < 0.01)
            return palpite;
            
        if (est < n){
            return raiz(n, palpite * 1.5);
        }
        return raiz(n, palpite * 0.5);
    }
    
    double absoluto(double a){
        
        if (a < 0)
            return a * -1;
        return a;
    }