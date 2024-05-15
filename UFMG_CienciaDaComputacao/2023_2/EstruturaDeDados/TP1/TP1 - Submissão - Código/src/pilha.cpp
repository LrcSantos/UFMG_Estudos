#include "../include/pilha.hpp"

//Construtor
Pilha::Pilha() {
    tamanho = 0;
    topo = NULL;
}

//Destrutor
Pilha::~Pilha() {
    Limpa();
}

//Métodos

//Retorna o tamanho da pilha
int Pilha::Tamanho() const {
    return tamanho;
}

//Retorna true se a pilha estiver vazia
bool Pilha::Vazia() const{
    return tamanho == 0;
}

//Empilha um item na pilha
void Pilha::Empilha(int item) {
    Node* novo = new Node;
    novo->data = item;
    novo->next = topo;
    topo = novo;
    tamanho++;
}

//Desempilha um item da pilha
int Pilha::Desempilha() {
    if (Vazia()) {
        throw std::runtime_error("A pilha está vazia!");
    }

    int item = topo->data;
    Node* temp = topo;
    topo = topo->next;
    delete temp;
    tamanho--;
    return item;
}

//Retorna o item do topo da pilha
int Pilha::Topo() const {
    if (Vazia()) {
        throw std::runtime_error("A pilha está vazia!");
    }

    return topo->data;
}

//Limpa a pilha
void Pilha::Limpa() {
    while(!Vazia())
        Desempilha();
}

//Imprime a pilha
void Pilha::Imprime() {
    Node* temp = topo;
    while(temp != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}


