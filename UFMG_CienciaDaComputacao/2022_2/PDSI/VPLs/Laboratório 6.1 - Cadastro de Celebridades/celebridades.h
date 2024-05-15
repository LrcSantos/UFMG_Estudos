#ifndef CELEBRIDADES_H_
#define CELEBRIDADES_H_

// TODO: Declare aqui seu tipo de dados celebridade
typedef struct Celebridade {
    char nome[100];
    char data[10];

} Celebridade;

struct Celebridade c[100];

Celebridade le_celebridade(int i);
void exibe_celebridade(Celebridade c);

// O parâmetro cs é um arranjo de n celebridades
void adiciona_celebridades(Celebridade *cs, int n);
void exibe_celebridades(Celebridade *cs, int n);

#endif