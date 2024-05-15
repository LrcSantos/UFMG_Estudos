#include "func.h"
#include <stdlib.h>
#include <stdio.h>


    double** aloca_matriz(int linha, int coluna){
        int i;
        double **A;
        A = (double **) malloc(linha *(sizeof(double)));
        
        for (i = 0; i < linha; i++){
            A[i] = (double *) malloc (coluna * sizeof (double));
        }
        return A;
    }
    void le_matriz(double **matriz, int n, int m){
        
        int i, j;
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                double x;
                scanf("%lf", &x);
                matriz[i][j] = x;
            }
        }
    }
    
    double** produto_matricial(double** matriz1, double** matriz2, int n, int m){
        
        int i, j;
        double **P = aloca_matriz(n, n);
            for(int i = 0; i < n; i++){
                for(int p = 0; p < n; p++){
                    double soma = 0;
                    for(j = 0; j < m; j++){
                        soma += matriz1[i][j] * matriz2[j][p];   
                    }
                    P[i][p] = soma;
                }
            }
        return P;
    }

    void exibe_matriz(double **matriz, int n, int m){
        
        int i, j;
        
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                printf("%lf ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    void libera_matrix(double **matriz, int n){
        
        free ((double**)matriz);
    }