#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    int a = 0;
    int e = 0;
    int i = 0;
    int o = 0;
    int u = 0;
    int j = 0;
    int n;

    char str[100];
    
    fgets(str, 100, stdin);

    
    n = strlen(str);
    
        for (j = 0; j < n; j++){
            switch (str[j]) {
        
                case 'A': a++; break;
                case 'a': a++; break;
                case 'E': e++; break;
                case 'e': e++; break;
                case 'I': i++; break;
                case 'i': i++; break;
                case 'O': o++; break;
                case 'o': o++; break;
                case 'U': u++; break;
                case 'u': u++; break;
                default: break;
            
            }
    }
    
    printf("A: %d E: %d I: %d O: %d U: %d\n", a, e, i, o, u);
    
    return 0;
}