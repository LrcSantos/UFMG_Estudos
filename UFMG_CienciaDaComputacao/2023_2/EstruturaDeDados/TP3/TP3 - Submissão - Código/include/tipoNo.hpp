#ifndef TIPONO_HPP
#define TIPONO_HPP

#include <iostream>

struct Matrix {
    int a, b, c, d; // Representa a matriz [a, b; c, d]
};

Matrix multiply(const Matrix& m1, const Matrix& m2);

class TipoNo {
public:
    TipoNo();
    
private:
    Matrix matriz; // Matriz associada a este nó
    TipoNo *esq;
    TipoNo *dir;

    friend class SegTree;
};

#endif