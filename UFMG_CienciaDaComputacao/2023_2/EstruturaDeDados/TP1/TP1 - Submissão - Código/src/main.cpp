#include <iostream>
#include <cstdlib>
#include <stdexcept>

#include "../include/pilha.hpp"
#include "../include/avaliarExpressao.hpp"

int main(int argc, char** argv) {
    
    //Argumentos: -a <expressao_logica> <string_valores>
    if (argc != 4) {
        std::cerr << "Uso: " << argv[0] << " <opcao> <expressao_logica> <string_valores>" << std::endl;
        return 1;
    }

    std::string opcao = argv[1];
    std::string expressao = argv[2];
    std::string valores = argv[3];

    if (opcao != "-a" && opcao != "-s") {
        std::cerr << "Opcao invalida: " << opcao << std::endl;
        return 1;
    }

    if (expressao.empty()) {
        std::cerr << "Expressao invalida: " << expressao << std::endl;
        return 1;
    }

    if (valores.empty()) {
        std::cerr << "Valores invalidos: " << valores << std::endl;
        return 1;
    }

    // Avaliação de Expressões
    if (opcao == "-a") {
        try {
            int resultado = avaliarExpressao(expressao, valores);
            std::cout << resultado << std::endl;
        } 
        catch (const std::runtime_error& e) {
            std::cerr << "Erro: " << e.what() << std::endl;
            return 1;
        }
    } 

    // Satisfatibilidade
    else if (opcao == "-s") {
        satisfatibilidade(expressao, valores);
    } 
    else {
        std::cerr << "Opcao invalida: " << opcao << std::endl;
    }

    return 0;
}