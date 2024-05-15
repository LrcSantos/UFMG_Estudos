#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"

int main(int argc, char *argv[]){
    
    char arquivo[100];
    scanf("%s", arquivo);
    
    int n, i;
    scanf("%d\n", &n);

    for (i = 0; i < n; i++){
        Contato c = criar_contato();
        inserir_contato(c, arquivo);
    }

    exibir_contatos(arquivo);
    
    return 0;
}