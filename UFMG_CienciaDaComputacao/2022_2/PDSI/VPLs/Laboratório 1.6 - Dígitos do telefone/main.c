#include <stdio.h>

int main(int argc, char *argv[]) {
    
    char ch;
    int a = 0;
    
    printf("Digite uma letra:\n");
    scanf("%c", &ch);
    
    if (ch == 'a' || ch == 'b' || ch == 'c')
    {
        a = 2;
    }
    
    else if (ch == 'd' || ch == 'e' || ch == 'f')
    {
        a = 3;
    }
    
        else if (ch == 'g' || ch == 'h' || ch == 'i')
    {
        a = 4;
    }
    
        else if (ch == 'j' || ch == 'k' || ch == 'l')
    {
        a = 5;
    }
    
        else if (ch == 'm' || ch == 'n' || ch == 'o')
    {
        a = 6;
    }
    
        else if (ch == 'p' || ch == 'q' || ch == 'r')
    {
        a = 7;
    }
    
        else if (ch == 's' || ch == 't' || ch == 'u')
    {
        a = 8;
    }
    
        else if (ch == 'v' || ch == 'w' || ch == 'x')
    {
        a = 9;
    }
    
        else if (ch == 'y' || ch == 'z')
    {
        a = 0;
    }
    
    printf("%d\n", a);
    return 0;
}