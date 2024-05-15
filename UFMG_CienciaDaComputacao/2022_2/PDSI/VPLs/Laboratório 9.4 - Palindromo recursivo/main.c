#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindromo.h"

int main(int argc, char *argv[]) {
    char palavra[1000];
    scanf("%s", palavra);
    int n = 0;
    for (;n < 1000 && palavra[n] != '\0'; n++);
    int p = palindromo(palavra, 0, n-1);
    printf("%d", p);
    return 0;
}
