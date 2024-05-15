#include <stdio.h>

int main(int argc, char *argv[]) {
    
    float valor;
    char estado;
    
    printf("Digite o valor do produto:\n");
    scanf("%f", &valor);
    
    printf("Digite o qual é o estado:\n");
    scanf("%s", &estado);
    
    float imposto;
    double valor_final;
    
    switch (estado) {
        
        case 'M': imposto = 0.07; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'm': imposto = 0.07; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'S': imposto = 0.12; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 's': imposto = 0.12; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'R': imposto = 0.15; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'r': imposto = 0.15; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'B': imposto = 0.08; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        case 'b': imposto = 0.08; valor_final = (valor * imposto) + valor; printf("Entrada: %.2f %c\nSaída: %.2f\n", valor, estado, valor_final); break;
        default: printf("Estado Inválido!\n");
        
    }
    
    return 0;
}