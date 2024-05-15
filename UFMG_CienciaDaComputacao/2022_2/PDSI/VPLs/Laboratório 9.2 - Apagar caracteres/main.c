#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "string_extra.h"

int main(int argc, char *argv[]) {
    char str[100];
    fgets(str, 100, stdin);

    char c = getchar();

    apaga_caractere(str, c);
    printf("%s", str);

    return 0;
}
