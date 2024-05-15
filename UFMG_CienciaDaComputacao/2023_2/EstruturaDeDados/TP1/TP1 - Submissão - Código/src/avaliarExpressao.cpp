#include "../include/avaliarExpressao.hpp"

// Função que verifica se um caractere é um operador lógico
bool ehOperador(char c) {
    return (c == '&' || c == '|' || c == '~');
}

// Função que a precedência dos operadores
int precedencia(char c) {
    if (c == '~') return 3; // Negação
    if (c == '&') return 2; // Conjunção
    if (c == '|') return 1; // Disjunção
    return 0; // Operador inválido
}

// Função que simplifica uma expressão lógica
std::string simplificarExpressao(const std::string& p) {
    std::string expressaoSimplificada;
    bool negacaoAtiva = false;

    for (std::string::size_type i = 0; i < p.length(); i++) {
        char token = p[i];
        if (token == '~') {
            negacaoAtiva = !negacaoAtiva; // Inverte o estado da negação
        } 
        else {
            if (token != ' ') {
                if (negacaoAtiva) {
                    // Se negação estiver ativa, adicione uma única negação
                    expressaoSimplificada += '~';
                    negacaoAtiva = false;
                }
                expressaoSimplificada += token;
            }
        }
    }

    // Verifique a negação no final
    if (negacaoAtiva) {
        expressaoSimplificada += '~';
    }

    return expressaoSimplificada;
}

//Função que avalia uma expressão lógica
int avaliarExpressao(const std::string& p, const std::string& s) {
    std::string expressaoSimplificada = simplificarExpressao(p);
    Pilha operandStack;
    Pilha operatorStack;

    for (std::string::size_type i = 0; i < expressaoSimplificada.length(); i++) {
        char token = expressaoSimplificada[i];
        if (token == ' ') {
            continue;
        } 
        else if (isdigit(token)) {
            std::string::size_type variavel = token - '0';
            if (variavel < 0 || variavel >= s.length()) {
                throw std::runtime_error("Variável fora de alcance na string de valores.");
            }
            int valor = s[variavel] - '0';
            operandStack.Empilha(valor);
        } 
        else if (token == '(') {
            operatorStack.Empilha(token);
        } 
        else if (token == ')') {
            while (!operatorStack.Vazia() && operatorStack.Topo() != '(') {
                char operador = operatorStack.Desempilha();
                if (operador == '~') {
                    operandStack.Empilha(!operandStack.Desempilha());
                } 
                else {
                    int op2 = operandStack.Desempilha();
                    int op1 = operandStack.Desempilha();
                    if (operador == '&') {
                        operandStack.Empilha(op1 && op2);
                    } 
                    else if (operador == '|') {
                        operandStack.Empilha(op1 || op2);
                    }
                }
            }
            if (!operatorStack.Vazia() && operatorStack.Topo() == '(') {
                operatorStack.Desempilha();
            }
        } 
        else if (ehOperador(token)) {
            while (!operatorStack.Vazia() && precedencia(operatorStack.Topo()) >= precedencia(token)) {
                char operador = operatorStack.Desempilha();
                if (operador == '~') {
                    operandStack.Empilha(!operandStack.Desempilha());
                } 
                else {
                    int op2 = operandStack.Desempilha();
                    int op1 = operandStack.Desempilha();
                    if (operador == '&') {
                        operandStack.Empilha(op1 && op2);
                    } 
                    else if (operador == '|') {
                        operandStack.Empilha(op1 || op2);
                    }
                }
            }
            operatorStack.Empilha(token);
        }
    }

    while (!operatorStack.Vazia()) {
        char operador = operatorStack.Desempilha();
        if (operador == '~') {
            operandStack.Empilha(!operandStack.Desempilha());
        } 
        else {
            int op2 = operandStack.Desempilha();
            int op1 = operandStack.Desempilha();
            if (operador == '&') {
                operandStack.Empilha(op1 && op2);
            } 
            else if (operador == '|') {
                operandStack.Empilha(op1 || op2);
            }
        }
    }

    if (operandStack.Vazia() || operandStack.Tamanho() != 1) {
        throw std::runtime_error("Expressão inválida: operandos em falta ou operadores em excesso.");
    }

    return operandStack.Topo();
}

//Funçao que avalia uma expressão lógica (Expressões de satisfatibilidade)
int avaliarSast(const std::string& p, const std::string& s) {
    std::string expressaoSimplificada = simplificarExpressao(p);
    Pilha operandStack;
    Pilha operatorStack;

    for (std::string::size_type i = 0; i < expressaoSimplificada.length(); i++) {
        char token = expressaoSimplificada[i];
        if (token == ' ') {
            continue;
        } 
        else if (isdigit(token)) {
            std::string::size_type variavel = token - '0';
            if (variavel < 0 || variavel >= s.length()) {
                throw std::runtime_error("Variável fora de alcance na string de valores.");
            }
            int valor = s[variavel] - '0';
            operandStack.Empilha(valor);
            while (i + 1 < expressaoSimplificada.length() && expressaoSimplificada[i + 1] == '~') {
                int op = operandStack.Desempilha();
                operandStack.Empilha(!op);
                i++;
            }
        } 
        else if (token == '(') {
            operatorStack.Empilha(token);
        } 
        else if (token == ')') {
            while (!operatorStack.Vazia() && operatorStack.Topo() != '(') {
                char operador = operatorStack.Desempilha();
                if (operador == '~') {
                    int op = operandStack.Desempilha();
                    operandStack.Empilha(!op);
                } 
                else {
                    int op2 = operandStack.Desempilha();
                    int op1 = operandStack.Desempilha();
                    if (operador == '&') {
                        operandStack.Empilha(op1 && op2);
                    } 
                    else if (operador == '|') {
                        operandStack.Empilha(op1 || op2);
                    }
                }
            }
            if (!operatorStack.Vazia() && operatorStack.Topo() == '(') {
                operatorStack.Desempilha();
            }
        } 
        else if (ehOperador(token)) {
            while (!operatorStack.Vazia() && precedencia(operatorStack.Topo()) >= precedencia(token)) {
                char operador = operatorStack.Desempilha();
                if (operador == '~') {
                    int op = operandStack.Desempilha();
                    operandStack.Empilha(!op);
                } 
                else {
                    int op2 = operandStack.Desempilha();
                    int op1 = operandStack.Desempilha();
                    if (operador == '&') {
                        operandStack.Empilha(op1 && op2);
                    } 
                    else if (operador == '|') {
                        operandStack.Empilha(op1 || op2);
                    }
                }
            }
            operatorStack.Empilha(token);
        }
    }

    while (!operatorStack.Vazia()) {
        char operador = operatorStack.Desempilha();
        if (operador == '~') {
            int op = operandStack.Desempilha();
            operandStack.Empilha(!op);
        } 
        else {
            int op2 = operandStack.Desempilha();
            int op1 = operandStack.Desempilha();
            if (operador == '&') {
                operandStack.Empilha(op1 && op2);
            } 
            else if (operador == '|') {
                operandStack.Empilha(op1 || op2);
            }
        }
    }

    if (operandStack.Vazia()) {
        throw std::runtime_error("Expressão inválida: operandos em falta.");
    }

    return operandStack.Topo();
}

//Função que gera todas as combinações possíveis de uma string
void gerarCombinacoes(std::string& str, std::string* combinations, int& numCombinations) {
    const int maxCombinations = 1 << str.length();
    
    for (int combinationIndex = 0; combinationIndex < maxCombinations; combinationIndex++) {
        combinations[combinationIndex] = str;
        
        for (std::string::size_type i = 0; i < str.length(); i++) {
            if (str[i] == 'a') {
                str[i] = ((combinationIndex >> i) & 1) ? '1' : '0';
            } else if (str[i] == 'e') {
                str[i] = ((combinationIndex >> i) & 1) ? '1' : '0';
            }
        }
    }
    numCombinations = maxCombinations;
}

//Função que checa a satisfatibilidade de uma expressão lógica
void satisfatibilidade(const std::string& p, const std::string& s) {
    const int maxCombinations = 1 << s.length(); 
    std::string* combinations = new std::string[maxCombinations];
    int numCombinations = 0;

    std::string currentCombination = s;
    gerarCombinacoes(currentCombination,combinations, numCombinations);

    std::string resultString = "";

    for (int combinationIndex = 0; combinationIndex < numCombinations; combinationIndex++) {
        const std::string& combination = combinations[combinationIndex];
        int result = avaliarSast(p, combination);

        // Atualiza a string resultante com base no resultado atual
        for (std::string::size_type i = 0; i < combination.length(); i++) {
            if (result == 1) {
                if (resultString.length() <= i) {
                    resultString += combination[i]; // Inicializa com o valor atual
                } 
                else {
                    if (combination[i] != resultString[i]) {
                        resultString[i] = 'a'; // Pode ser tanto 0 quanto 1
                    }
                }
            }
        }
    }

    if (resultString.empty()) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1" << " " << resultString << std::endl;
    }

    delete[] combinations;
}