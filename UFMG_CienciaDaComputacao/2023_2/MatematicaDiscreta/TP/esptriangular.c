#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime(int n, int x, int y) {
    printf("Ponto: %d Coordenadas: (%d, %d)\n", n, x, y);
}

int calculaCoordenadas(int n, int *x, int *y) {
    if (n < 0) {
        return -1; // Erro: Valor incorreto
    }

    int raiz = sqrt(n); // Calcula a parte inteira da raiz de n
    int metadeRaiz = raiz / 2; //Calcula a metade da raiz

    if (n == raiz * raiz) {
        // Vertice Inferior esquerdo | Inferior direito
        *x = (raiz % 2 == 0) ? -raiz : raiz;
        *y = (raiz % 2 == 0) ? -metadeRaiz : -metadeRaiz;
    } 
   else if (n == raiz * raiz + raiz) {
        // Topo | Meio
        *x = 0;
        *y = (raiz % 2 != 0) ? metadeRaiz + 1 : -metadeRaiz;
    }

    else {
        // Não é vertice, meio ou topo

        // Calcula os limites (Vértices, Meio ou Topo)
        int chao = raiz * raiz + raiz;
        int teto = (n > chao) ? (raiz + 1) * (raiz + 1) : raiz * raiz; 
        int temp;
        // Armazena o menor valor em chao e o maior em teto
        if (chao > teto) {
            temp = chao;
            chao = teto;
            teto = temp;
        }
        // Calcula as raizes dos limites
        int raiz1 = sqrt(chao);
        int raiz2 = sqrt(teto);

        // Calcula as coordenadas de acordo com os limites

        // Verifica se n está entre o Meio e o Vértice Inferior direito
        if ((chao == raiz1 * raiz1 + raiz1 && raiz1 % 2 == 0) && (teto == raiz2 * raiz2 && raiz2 % 2 != 0)) {
            *x = n - chao;
            *y = -metadeRaiz;
        }
        // Verifica se n está entre o Vértice Inferior direito e o Topo
        else if ((chao == raiz1 * raiz1 && raiz1 % 2 != 0) && (teto == raiz2 * raiz2 + raiz2 && raiz2 % 2 != 0)) {
            *x = raiz - (n - chao);
            *y = -metadeRaiz + (n - chao); 
        }
        // Verifica se n está entre o Topo e o Vértice Inferior esquerdo
        else if ((chao == raiz1 * raiz1 + raiz1 && raiz1 % 2 != 0) && (teto == raiz2 * raiz2 && raiz2 % 2 == 0)) {
            *x = 0 - (n - chao);
            *y = metadeRaiz + 1 - (n - chao);
        }
        // Verifica se n está entre o Vértice Inferior esquerdo e o Meio
        else if ((chao == raiz1 * raiz1 && raiz1 % 2 == 0) && (teto == raiz2 * raiz2 + raiz2 && raiz2 % 2 == 0)) {
            *x = -raiz + (n - chao);
            *y = -metadeRaiz;        
        }
    }

    return 0;
}

int main() {
    int n, x, y;
    scanf("%d", &n);

    int resultado = calculaCoordenadas(n, &x, &y);

    if (resultado == -1) {
        printf("Ponto inválido\n");
        exit(EXIT_FAILURE);
    }

    imprime(n, x, y);

    return 0;
}