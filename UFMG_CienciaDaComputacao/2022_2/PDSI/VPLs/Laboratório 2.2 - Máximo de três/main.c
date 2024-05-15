#include <stdio.h>

int main(int argc, char *argv[]) {

    int a, b, c;
    int m;
    
    printf ("Digite três números inteiros:\n");
    scanf ("%d %d %d", &a, &b, &c);
  
    m = a;
    m = (a >= m) ? a : m; 
        m = (b >= m) ? b : m; 
            m = (c >= m) ? c : m; 
    
    
    printf("%d", m);
    
    return 0;
}