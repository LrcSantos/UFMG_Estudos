#include <stdio.h>
#include "evento.h"

int main(int argc, char *argv[]){
    int n;
    scanf("%d", &n);
    
    Evento agenda[100];
    cadastrar_eventos(agenda, n);
    
    Data d;
    int dia;
    scanf("%d", &d.dia);

    int mes;
    scanf("%d", &mes);
    d.mes = mes;
    
    int ano;
    scanf("%d", &d.ano);
    
    imprimir_eventos(agenda, d, n);
    
    return 0;
}