#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void imprime(int n, int x, int y) {
    printf("Ponto: %d Coordenadas: (%d, %d)", n, x, y);
}

int calculaCoordenadas(int n, int *x, int *y) {
    if (n < 0) {
        return -1; // Erro: Valor incorreto
    }

    int raiz = sqrt(n); // Calcula a parte inteira da raiz de n
    int metadeRaiz = raiz / 2; //Calcula a metade da raiz

    if (n == raiz * raiz) {
        // Vertice Inferior esquerdo | Superior direito
        *x = (raiz % 2 == 0) ? -metadeRaiz : metadeRaiz;
        *y = (raiz % 2 == 0) ? -metadeRaiz : metadeRaiz + 1;
    } 
   else if (n == raiz * raiz + raiz) {
        // Vertice Inferior direito | Superior esquerdo
        *x = (raiz % 2 == 0) ? metadeRaiz : -(metadeRaiz + 1);
        *y = (raiz % 2 == 0) ? -metadeRaiz : metadeRaiz + 1;
    }

    else {
        // Não é vertice

        // Calcula os limites (Vértices)
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

        // Calcula as coordenada de acordo com os limites

        // Verifica se n está entre um Vértice Inferior direito e um Superior direito
        if ((chao == raiz1 * raiz1 + raiz1 && raiz1 % 2 == 0) && (teto == raiz2 * raiz2 && raiz2 % 2 != 0)) {
            *x = metadeRaiz;
            *y = -metadeRaiz + (n - chao);
        }
        // Verifica se n está entre um Vértice Superior direito e um Superior esquerdo
        else if ((chao == raiz1 * raiz1 && raiz1 % 2 != 0) && (teto == raiz2 * raiz2 + raiz2 && raiz2 % 2 != 0)) {
            *x = metadeRaiz - (n - chao);
            *y = metadeRaiz + 1; 
        }
        // Verifica se n está entre um Vértice Superior Esquerdo e um Inferior esquerdo
        else if ((chao == raiz1 * raiz1 + raiz1 && raiz1 % 2 != 0) && (teto == raiz2 * raiz2 && raiz2 % 2 == 0)) {
            *x = -(metadeRaiz + 1);
            *y = metadeRaiz + 1 - (n - chao);
        }
        // Verifica se n está entre um Vértice Inferior esquerdo e um Inferior direito
        else if ((chao == raiz1 * raiz1 && raiz1 % 2 == 0) && (teto == raiz2 * raiz2 + raiz2 && raiz2 % 2 == 0)) {
            *x = -metadeRaiz + (n - chao);
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