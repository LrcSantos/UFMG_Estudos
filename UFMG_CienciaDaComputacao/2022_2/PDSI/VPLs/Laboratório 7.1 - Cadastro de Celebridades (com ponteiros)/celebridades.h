#ifndef CELEBRIDADES_H_
#define CELEBRIDADES_H_

typedef struct celebridade {
    char nome[100];
    int dia_nascimento;
    int mes_nascimento;
    int ano_nascimento;
} celebridade;

// TODO: Declare aqui seu tipo de dados celebridade

void le_celebridade(celebridade *c);

void exibe_celebridade(celebridade *c);

void adiciona_celebridades(celebridade *c, int n);

void exibe_celebridades(celebridade *c, int n);

#endif // CELEBRIDADES_H_