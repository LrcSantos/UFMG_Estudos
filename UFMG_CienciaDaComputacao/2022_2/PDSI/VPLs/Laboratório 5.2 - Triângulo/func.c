#include "func.h"

int eh_triangulo(float a, float b, float c){
    
	int t = 0;
	
	if(a < b + c && b < a + c && c < a + b){
		t = 1;
	}
	
	return t;
	
}

int tipo_triangulo(float a, float b, float c){
    
    int p;
    
    if (a != b && a != c && b != c){
        p = 0;
    }
    else if (a == b && a != c || a == c && a != b || b == c && b != a){
        p = 1;
    }
    else if (a == b && a == c){
        p = 2;
    }
	
	return p;
	
}