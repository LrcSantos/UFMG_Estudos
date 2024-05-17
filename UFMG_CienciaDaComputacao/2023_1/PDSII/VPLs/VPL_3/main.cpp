/*
O objetivo desse VPL é praticar a escrita de funções em C++. Serão feitas duas funções: uma que calcula o fatorial,  outra que conta a quantidade de inteiros em um intervalo. Para terminar esse VPL, você deverá completar o código dessas duas funções dentro do arquivo Main.cpp.

A função fatorial recebe um número inteiro. Caso esse número seja negativo, o valor 1 deve ser retornado:


fatorial(3) == 6

fatorial(2) == 2


fatorial(1) == 1

fatorial(0) == 1

fatorial(-1) == 1

A função intervalo conta a quantidade de inteiros entre dois números de ponto flutuante. A contagem é inclusiva. Isso é, caso o número de ponto flutuante também seja um inteiro, ele deve ser contado. Exemplos:


intervalo(3.0, 5.0) == 3

intervalo(2.01, 2.9) == 0


intervalo(0.999, 1.001) == 1

Dica:
Lembre-se que para testar localmente, você pode usar o seguinte comado: ./executavel < in.txt, onde o arquivo in.txt possui os dados que serão utilizados como entrada.
Não altere a função main: ela contém um switch para escolher o caso de teste que será usado.
*/


#include <iostream>

/**
 * @brief Calcula o fatorial de um numero inteiro
 * 
 * Esta funcao nao faz tratamento de erros: se o numero passado como parametro
 * for igual ou menor a zero, entao ela retorna o valor 1.
 * 
 * @param arg O numero cujo fatorial sera calculado
 * @return unsigned O valor do fatorial de arg. Se arg for igual ou menor a
 * zero, entao o valor retornado deve ser 1.
 */
unsigned factorial(int arg) {
    int fat = arg;
    if (arg <= 0) {
        return 1;
    }
    if (arg > 0) {
        for (int i = arg - 1; i > 0; i--) {
            fat = fat * i;
        }
    }
    return fat;
}

/**
 * @brief Conta a quantidade de inteiros em um certo interval.
 * 
 * O intervalo eh formado por dois numeros de ponto flutuante (doubles). A
 * contagem eh inclusiva. Assim, entre 1.0 e 3.0 existem tres inteiros
 * (1, 2 e 3), mas entre 0.2 e 0.9 nao existe nenhum.
 * 
 * @param start O inicio do intervalo
 * @param end O final do interval
 * @return unsigned O numero de inteiros contidos dentro do intervalo
 * (inclusive)
 */
unsigned interval(double start, double end) {
    int som = 0;
    for (int i = end; i >= start; i--) {
        som += 1;
    }
    return som;
}

int main() {
  char test = 0;
  std::cin >> test;
  switch (test) {
    case 'f': {
      int arg = 0;
      std::cin >> arg;
      std::cout << factorial(arg) << std::endl;
    }
    break;
    case 'i': {
      double arg0 = 0;
      double arg1 = 0;
      std::cin >> arg0 >> arg1;
      std::cout << interval(arg0, arg1) << std::endl;
    }
    break;
  }
}