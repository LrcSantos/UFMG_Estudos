#ifndef FUNC_H_
#define FUNC_H_


double** aloca_matriz(int n, int m);
void le_matriz(double **matriz, int n, int m);
double** soma_matricial(double** matriz1, double** matriz2, int n, int m);
void exibe_matriz(double **matriz, int n, int m);
void libera_matrix(double **matriz, int n);

#endif