#include "auth.h"

#include <stdlib.h>
#include <string.h>

#define TAM_ALFABETO 26
char *vignere(char *texto, char *chave) {
    int n = strlen(chave);
    int m = strlen(texto);
    
    char *text = (char*) malloc((m+1)*sizeof(char));
    int *codigo = (int*) malloc((m+1)*sizeof(int));

    int j = 0;
    
    for (int i = 0; i < m; i++, j++) {
        codigo[i] = (int)chave[j] - 'a';
        if (j >= n-1) {
            j = -1;
        }
    }
    
    for (int i = 0; i < m; i++) {
        text[i] = ((int)texto[i] - 'a') + codigo[i];
        if ((int)text[i] > 25){
            text[i] = (int)text[i] - 26;
        }
        text[i] = (int)text[i] + 'a';
    }
    return text;
}

char *des_vignere(char *cifrado, char *chave) {
    int n = strlen(chave);
    int m = strlen(cifrado);
    
    char *cif = (char*) malloc((m+1)*sizeof(char));
    
    int *codigo = (int*) malloc((m+1)*sizeof(int));
    int j = 0;
    
    for (int i = 0; i < m; i++, j++) {
        codigo[i] = (int)chave[j] - 'a';
        if (j >= n-1) {
            j = -1;
        }
    }
    
    for (int i = 0; i < m; i++) {
        cif[i] = ((int)cifrado[i] - 'a') - codigo[i];
        if (cif[i] < 0) {
            cif[i] = (int)cif[i] + 26;
        }
        cif[i] = (int)cif[i] + 'a';
    }
    return cif;
}

bool autenticar(Usuario u, BancoDados bd) {
    for (int i = 0; i < bd.n; i++) {
        if (strcmp(u.usuario, bd.usuarios[i].usuario) == 0)
             if (strcmp(u.senha, des_vignere(bd.usuarios[i].senha, u.usuario)) == 0)
                return true;
    } 
    return false;
}