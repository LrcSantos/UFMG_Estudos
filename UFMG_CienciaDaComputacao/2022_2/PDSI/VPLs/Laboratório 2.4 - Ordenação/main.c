#include <stdio.h>

int main(int argc, char *argv[]) {
    
    int a, b, c;
    int m, n, o;
    
    printf ("Digite três números inteiros:\n");
    scanf ("%d %d %d", &a, &b, &c);
  
    m = a;
    m = (a >= m) ? a : m; 
        m = (b >= m) ? b : m; 
            m = (c >= m) ? c : m; 
            
    n = m;
    n = (a <= n) ? a : n; 
        n = (b <= n) ? b : n; 
            n = (c <= n) ? c : n; 
            
    o = n;
    o = (a < m && a > n) ? a : o; 
        o = (b < m && b > n) ? b : o; 
            o = (c < m && c > n) ? c : o; 
    
    
    printf("Entrada: %d %d %d\n", a, b, c );
    printf("Saída: %d %d %d\n", n, o, m );
    
    return 0;
}