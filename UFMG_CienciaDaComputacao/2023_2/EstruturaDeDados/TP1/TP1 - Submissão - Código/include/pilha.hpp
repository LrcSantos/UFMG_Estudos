#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>

//Estrutura Nó
struct Node {
    int data;
    Node* next;
};

//Classe Pilha
class Pilha {

    public:
        Pilha();
        ~Pilha();
        bool Vazia() const; 
        void Empilha(int item);
        int Desempilha();
        void Limpa();
        void Imprime();
        int Topo() const;
        int Tamanho() const;
    
    private:
        Node* topo;
        int tamanho;
};

#endif
