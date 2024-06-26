#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFFER 50
    
    char *read_line(FILE *stream){
        
        char *buffer = (char *) malloc(TAM_BUFFER * sizeof(char));
        fgets(buffer, TAM_BUFFER, stream);
    
        int i = 2;
        while (!feof(stream) && buffer[strlen(buffer) - 1] != '\n') {
            buffer = (char *) realloc(buffer, TAM_BUFFER * i * sizeof(char));
            fgets(buffer + strlen(buffer), TAM_BUFFER, stream);
        }
    
        int tam_nome = strlen(buffer);
        buffer[tam_nome - 1] = '\0'; 
        buffer = (char *) realloc(buffer, tam_nome * sizeof(char));
    
        return buffer;
    }
    
    Contato criar_contato(void){
        
        Contato c;
    
        c.nome = read_line(stdin);
    
        scanf("%d\n", &c.idade);
        fgets(c.celular, 12, stdin);
    
        getchar(); 
        
        return c;
    }
    
    bool inserir_contato(Contato c, char *arquivo){
        
        FILE *p = fopen(arquivo, "a");
    
        if (p == NULL) {
            
            return false;
        }
    
        fprintf(p, "%s#%d#%s\n", c.nome, c.idade, c.celular);
    
        fclose(p);
        
        return true;
    }
    
    bool exibir_contatos(char *arquivo){
        
        FILE *p = fopen(arquivo, "r");
    
        if (p == NULL){
            
            return false;
        }
    
        char *contato = read_line(p);
        while (!feof(p)){
            printf("%s\n", contato);
            contato = read_line(p);
        }
    
        fclose(p);
        
        return true;
    }