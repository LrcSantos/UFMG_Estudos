#ifndef QUADRADO_H_
#define QUADRADO_H_

typedef struct Ponto {
    int x, y;
} Ponto;

struct Ponto p[4];

typedef struct Linha {
    struct Ponto i, f;
} Linha;

struct Linha l[4];

typedef struct Quadrado {
    struct Linha a, b, c, d;
} Quadrado;

struct Quadrado q[4];

Linha le_linha();
Quadrado le_quadrado();
void exibe_perimetro();
float pitagoras(int a, int b);

#endif // QUADRADO_H_