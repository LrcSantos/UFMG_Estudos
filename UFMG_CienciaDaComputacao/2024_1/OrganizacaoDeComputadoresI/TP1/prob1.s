.data
##### R1 START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#
vetor: .word 1 2 3 4 5 6 7 8 9 10
##### R1 END MODIFIQUE AQUI END #####
.text
 add s0, zero, zero #Quantidade de testes em que seu programa passou
 la a0, vetor
 addi a1, zero, 10
 addi a2, zero, 2
 jal ra, multiplos
 addi t0, zero, 5
 bne a0,t0,teste2
 addi s0,s0,1
teste2: la a0, vetor
 addi a1, zero, 10
 addi a2, zero, 3
 jal ra, multiplos
 addi t0, zero, 3
 bne a0,t0, FIM
 addi s0,s0,1
 beq zero,zero,FIM
 
##### R2 START MODIFIQUE AQUI START #####
multiplos:
    add t1, zero, zero      # Inicialização do contador de múltiplos
    mv t2, a2               # Armazenamos o valor de a2 em t2 

loop:
    lw t3, 0(a0)             # Carregamos o valor do vetor para t3
    rem t4, t3, t2           # Calculamos o resto da divisão de t3 por t2
    beqz t4, increment       # Se o resto for zero, é múltiplo (vamos para increment)
    addi a0, a0, 4           # Avança para o próximo elemento do vetor
    addi a1, a1, -1          # Decrementa o contador do tamanho do vetor
    bnez a1, loop            # Se ainda houver elementos no vetor (segue no loop)
    mv a0, t1                # Move o contador de múltiplos para o registrador de retorno
    jr ra                    # Retorna quando o vetor terminar

increment:
    addi t1, t1, 1           # Incrementa o contador de múltiplos
    addi a0, a0, 4           # Avança para o próximo elemento do vetor
    addi a1, a1, -1          # Decrementa o contador do tamanho do vetor
    bnez a1, loop            # Se ainda houver elementos no vetor (segue no loop)
    mv a0, t1                # Move o contador de múltiplos para o registrador de retorno
    jr ra                    # Retorna quando o vetor terminar

##### R2 END MODIFIQUE AQUI END #####
FIM: addi t0, s0, 0