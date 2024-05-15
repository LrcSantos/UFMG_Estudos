#ifndef AGENDA_H_
#define AGENDA_H_

#include <stdbool.h>

    typedef struct Contato{
        char *nome;
        unsigned int idade;
        char celular[15];
    }Contato;
    
    Contato criar_contato(void);
    
    bool inserir_contato(Contato c, char *arquivo);
    
    bool exibir_contatos(char *arquivo);

#endif // AGENDA_H_
