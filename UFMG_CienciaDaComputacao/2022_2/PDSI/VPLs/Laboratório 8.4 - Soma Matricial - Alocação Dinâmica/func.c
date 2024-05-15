#ifndef FUNC_C_
#define FUNC_C_
#include <stdlib.h>
#include <stdio.h>
    
    double** aloca_matriz(int n, int m){
        
        int i;
        
        double **A;
        A = (double **) malloc(n *(sizeof(double)));
        for (i = 0; i < n; i++){
            A[i] = (double *) malloc (m * sizeof (double));
        }
        return A;
    }
    
    void le_matriz(double **matriz, int n, int m){
        
        int i, j;
        
        for(i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                double x;
                scanf("%lf", &x);
                matriz[i][j] = x;
            }
        }
    }
    
    double** soma_matricial(double** matriz1, double** matriz2, int n, int m){
        
        int i, j;
        double **S = aloca_matriz(n, m);
        
            for(i = 0; i < n; i++){
                for(j = 0; j< m; j++){
                    S[i][j] = matriz1[i][j] + matriz2[i][j];
                }
            }
        
        return S;
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
    
    #endif
