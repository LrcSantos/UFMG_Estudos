#include "evento.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

    void cadastrar_eventos(Evento *agenda, int n){
    
        int i;
        for (i = 0; i < n; i++){
            
            Evento e;

            scanf("%s %s", e.nome, e.local);
            scanf("%d", &e.data.dia);

            int mes;
            scanf("%d", &mes);
            e.data.mes = mes;

            scanf("%d", &e.data.ano);
            agenda[i] = e;
        }
    }

    void imprimir_eventos(Evento *agenda, Data d, int n) {
        bool t = false;
        int i;
        for (i = 0; i < n; i++) {
            Evento e = agenda[i];
            if (
                e.data.dia == d.dia &&
                e.data.mes == d.mes &&
                e.data.ano == d.ano
            ) {
                printf("%s %s\n", e.nome, e.local);
                t = true;
            }
        }
    
        if (t == false){
            printf("Nenhum evento encontrado!\n");
        }
    }