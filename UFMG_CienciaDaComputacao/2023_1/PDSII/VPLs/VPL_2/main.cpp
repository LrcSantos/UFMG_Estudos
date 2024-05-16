/*
O objetivo desse VPL é praticar os comandos de entrada e saída específicos de C++ (cin, cout) e também a utilização do tipo string. Não utilize outros comando de entrada como o getline.

Escreva um programa que lê apenas uma única palavra da entrada. Em seguida, seu programa deve contar o número de vogais presente na palavra. Ao final, deve-se imprimir a quantidade de vezes que uma determinada vogal apareceu. Se uma vogal não apareceu nenhuma vez ela não deve ser impressa.

Para facilitar, você pode assumir que as palavras sempre terão todas as letras minúsculas.

Exemplos de entrada e saída:

input = 
estudantes

output = 
a 1
e 2
u 1


input = 
abacaxi

output = 
a 3
i 1
*/

#include <iostream>

int main() {
    std::string palavra;
    std::cin >> palavra;

    int vogais[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] == 'a') {
            vogais[0]++;
        } else if (palavra[i] == 'e') {
            vogais[1]++;
        } else if (palavra[i] == 'i') {
            vogais[2]++;
        } else if (palavra[i] == 'o') {
            vogais[3]++;
        } else if (palavra[i] == 'u') {
            vogais[4]++;
        }
    }

    if (vogais[0] > 0) {
        std::cout << "a " << vogais[0] << std::endl;
    }

    if (vogais[1] > 0) {
        std::cout << "e " << vogais[1] << std::endl;
    }

    if (vogais[2] > 0) {
        std::cout << "i " << vogais[2] << std::endl;
    }

    if (vogais[3] > 0) {
        std::cout << "o " << vogais[3] << std::endl;
    }

    if (vogais[4] > 0) {
        std::cout << "u " << vogais[4] << std::endl;
    }

    return 0;
    
}