#ifndef AVALIAREXPRESSAO_HPP
#define AVALIAREXPRESSAO_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

#include "pilha.hpp"

//Funções para avaliar uma expressão
bool ehOperador(char c);
int precedencia(char c);
std::string simplificarExpressao(const std::string& p); 
int avaliarExpressao(const std::string& p, const std::string& s);
int avaliarSast(const std::string& p, const std::string& s);
void gerarCombinacoes(std::string& str, std::string* combinations, int& numCombinations);
void satisfatibilidade(const std::string& p, const std::string& s);

#endif