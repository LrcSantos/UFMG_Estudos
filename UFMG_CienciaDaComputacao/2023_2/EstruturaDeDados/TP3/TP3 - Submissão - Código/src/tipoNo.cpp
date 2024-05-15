#include "../include/tipoNo.hpp"

TipoNo::TipoNo() {
    matriz = Matrix{1, 0, 0, 1}; // Matriz identidade
    esq = nullptr;
    dir = nullptr;
}

Matrix multiply(const Matrix& m1, const Matrix& m2) {
    Matrix result;
    result.a = (1LL * m1.a * m2.a + 1LL * m1.b * m2.c) % 100000000;
    result.b = (1LL * m1.a * m2.b + 1LL * m1.b * m2.d) % 100000000;
    result.c = (1LL * m1.c * m2.a + 1LL * m1.d * m2.c) % 100000000;
    result.d = (1LL * m1.c * m2.b + 1LL * m1.d * m2.d) % 100000000;
    
    // Ajuste para obter apenas os 8 dígitos menos significativos
    result.a = (result.a + 100000000) % 100000000;
    result.b = (result.b + 100000000) % 100000000;
    result.c = (result.c + 100000000) % 100000000;
    result.d = (result.d + 100000000) % 100000000;

    return result;
}