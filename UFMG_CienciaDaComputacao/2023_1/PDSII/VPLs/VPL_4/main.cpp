/*

Neste VPL vocês implementarão um Tipo Abstrato de Dados (TAD) usando structs.

Este TAD representa números complexos. 

A descrição dos dados e dos métodos associados a este TAD encontram-se no arquivo complexo.h

Qualquer código que opere sobre este TAD deve incluir este arquivo.



Exercício 1:

Implemente, no arquivo main.cpp, o TAD Complexo.



Exercício 2:

Uma vez que você tem o número complexo, implemente a função de computar as raízes, https://wikiciencias.casadasciencias.org/wiki/index.php/Ra%C3%ADzes_de_n%C3%BAmeros_complexos

*/

#include <iostream>
#include <cmath>
#include <utility>

    using namespace std;

    // Tipo abstrato de dados que representa um número complexo. 
    struct Complexo {
    // Atributos.
    double real;
    double imag;

    // Métodos.
    double modulo() {
        return sqrt(real*real + imag*imag);
    }
    
    Complexo conjugado() {
        Complexo c;
        c.real = real;
        c.imag = -imag;
        return c;
    }
    
    Complexo inverso() {
        Complexo i;
        double den = real*real + imag*imag;
        i.real = real/den;
        i.imag = -imag/den;
        return i;
    }
    
    Complexo soma(Complexo y) {
        Complexo s;
        s.real = real + y.real;
        s.imag = imag + y.imag;
        return s;
    }
    
    Complexo subtrair(Complexo y) {
        Complexo s;
        s.real = real - y.real;
        s.imag = imag - y.imag;
        return s;
    }
    
    Complexo multiplicar(Complexo y) {
        Complexo m;
        m.real = real*y.real - imag*y.imag;
        m.imag = imag*y.real + real*y.imag;
        return m;
    }
    
    Complexo dividir(Complexo y) {
        Complexo d;
        double den = y.real*y.real + y.imag*y.imag;
        d.real = (real*y.real + imag*y.imag)/den;
        d.imag = (imag*y.real - real*y.imag)/den;
        return d;
    }
    };

    // Função que calcula as raízes de uma equação do segundo grau.
    pair<Complexo, Complexo> raizes(double a, double b, double c) {
        Complexo delta, x1, x2;
        delta.real = b*b - 4*a*c;
        delta.imag = 0;

        if (delta.real >= 0) {
        x1.real = (-b + sqrt(delta.real))/(2*a);
        x2.real = (-b - sqrt(delta.real))/(2*a);
        x1.imag = x2.imag = 0;
        }
        
        else {
            delta.imag = sqrt(-delta.real)/(2*a);
            delta.real = -b/(2*a);
            x1.real = delta.real;
            x2.real = delta.real;
            x1.imag = delta.imag;
            x2.imag = -delta.imag;
        }

        return make_pair(x1, x2);
    }

    int main () {
        cout << "Digite os coeficientes da equação f(x) = ax^2 + bx + c:" << endl;
        double a, b, c;
        cin >> a >> b >> c;
        auto r = raizes(a, b, c);
        cout << "(" << r.first.real << ", " << r.first.imag << ") "
        << "(" << r.second.real << ", " << r.second.imag << ")" << endl;
        return 0;
    }