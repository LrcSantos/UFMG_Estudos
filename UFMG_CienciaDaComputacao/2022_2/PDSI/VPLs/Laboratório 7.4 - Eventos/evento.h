#ifndef EVENTO_H_
#define EVENTO_H_

typedef enum Mes { 
    JAN, FEV, MAR, ABR, MAI, JUN, JUL, AGO, SET, OUT, NOV, DEZ
} Mes;

typedef struct Data {
    int dia;
    enum Mes mes;
    int ano;
} Data;

typedef struct Evento {
    char nome[100];
    char local[100];
    Data data;
} Evento;

void cadastrar_eventos(Evento *agenda, int n);
void imprimir_eventos(Evento *agenda, Data d, int n);

#endif