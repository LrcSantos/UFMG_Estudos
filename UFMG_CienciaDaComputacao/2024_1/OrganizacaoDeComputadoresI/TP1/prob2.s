.data
##### R1 START MODIFIQUE AQUI START #####
#
# Este espaço é para você definir as suas constantes e vetores auxiliares.
#
vetor1: .word 1 2 3 4 #Primeiro vetor
vetor2: .word 1 1 1 1 #Segundo vetor
##### R1 END MODIFIQUE AQUI END #####
 
.text 
 add s0, zero, zero
 la a0, vetor1
 addi a1, zero, 4
 jal ra, media
 addi t0, zero, 2
 bne a0,t0,teste2
 addi s0,s0,1
teste2: la a0, vetor2
 addi a1, zero, 4
 jal ra, media
 addi t0, zero, 1
 bne a0,t0, FIM
 addi s0,s0,1
 beq zero,zero, FIM

##### R2 START MODIFIQUE AQUI START ##### 
# Função para calcular a média de um vetor
media:
    addi sp, sp, -8       # Reserva espaço na pilha para salvar s0 e s1
    sw s10, 0(sp)         # Salva s10 na pilha
    sw s1, 4(sp)          # Salva s1 na pilha

    mv s10, a0            # s10 = endereço inicial do vetor
    mv s1, a1             # s1 = quantidade de elementos

    add t0, zero, zero    # t0 = soma dos elementos
    add t1, zero, zero    # t1 = contador

    loop_media:
        lw t2, 0(s10)           # t2 = próximo elemento do vetor
        add t0, t0, t2          # Adiciona o elemento à soma
        addi s10, s10, 4        # Avança para o próximo elemento
        addi t1, t1, 1          # Incrementa o contador
        bne t1, s1, loop_media  # Verifica se todos os elementos foram somados

    div t0, t0, s1         # Calcula a média: soma / quantidade

    mv a0, t0              # Coloca o resultado (média) em a0

    lw s10, 0(sp)          # Restaura s10
    lw s1, 4(sp)           # Restaura s1
    addi sp, sp, 8         # Libera espaço na pilha
    jr ra                  # Retorna

# Função para calcular a covariância de dois vetores
covariancia:
    addi sp, sp, -32      # Reserva espaço na pilha para salvar s0-s5 e t0-t3
    sw s10, 0(sp)         # Salva s10 na pilha
    sw s1, 4(sp)          # Salva s1 na pilha
    sw s2, 8(sp)          # Salva s2 na pilha
    sw s3, 12(sp)         # Salva s3 na pilha
    sw s4, 16(sp)         # Salva s4 na pilha
    sw s5, 20(sp)         # Salva s5 na pilha
    sw t0, 24(sp)         # Salva t0 na pilha
    sw t1, 28(sp)         # Salva t1 na pilha

    mv s10, a0            # s10 = endereço inicial do primeiro vetor
    mv s1, a1             # s1 = endereço inicial do segundo vetor
    mv s2, a2             # s2 = quantidade de elementos

    add t0, zero, zero    # t0 = soma dos produtos
    add t1, zero, zero    # t1 = contador

    # Calcula a média dos vetores
    jal ra, media         # Chama a função media para o primeiro vetor
    mv s3, a0             # s3 = média do primeiro vetor
    jal ra, media         # Chama a função media para o segundo vetor
    mv s4, a0             # s4 = média do segundo vetor

    # Calcula a covariância
    loop_cov:
        lw t2, 0(s10)     # t2 = próximo elemento do primeiro vetor
        lw t3, 0(s1)      # t3 = próximo elemento do segundo vetor
        sub t2, t2, s3    # t2 = xi - média_x
        sub t3, t3, s4    # t3 = yi - média_y
        mul t2, t2, t3    # t2 = (xi - média_x) * (yi - média_y)
        add t0, t0, t2    # Adiciona o produto à soma dos produtos
        addi s10, s10, 4  # Avança para o próximo elemento do primeiro vetor
        addi s1, s1, 4    # Avança para o próximo elemento do segundo vetor
        addi t1, t1, 1    # Incrementa o contador
        bne t1, s2, loop_cov  # Verifica se todos os elementos foram processados

    div t0, t0, s2        # Calcula a covariância: soma dos produtos / quantidade - 1

    mv a0, t0             # Coloca o resultado (covariância) em a0

    lw s10, 0(sp)         # Restaura s10
    lw s1, 4(sp)          # Restaura s1
    lw s2, 8(sp)          # Restaura s2
    lw s3, 12(sp)         # Restaura s3
    lw s4, 16(sp)         # Restaura s4
    lw s5, 20(sp)         # Restaura s5
    lw t0, 24(sp)         # Restaura t0
    lw t1, 28(sp)         # Restaura t1
    addi sp, sp, 32       # Libera espaço na pilha
    jr ra                 # Retorna
    
# Mesma função, porém com nome de variancia
variancia:
    addi sp, sp, -32      # Reserva espaço na pilha para salvar s0-s5 e t0-t3
    sw s10, 0(sp)         # Salva s10 na pilha
    sw s1, 4(sp)          # Salva s1 na pilha
    sw s2, 8(sp)          # Salva s2 na pilha
    sw s3, 12(sp)         # Salva s3 na pilha
    sw s4, 16(sp)         # Salva s4 na pilha
    sw s5, 20(sp)         # Salva s5 na pilha
    sw t0, 24(sp)         # Salva t0 na pilha
    sw t1, 28(sp)         # Salva t1 na pilha

    mv s10, a0            # s10 = endereço inicial do primeiro vetor
    mv s1, a1             # s1 = endereço inicial do segundo vetor
    mv s2, a2             # s2 = quantidade de elementos

    add t0, zero, zero    # t0 = soma dos produtos
    add t1, zero, zero    # t1 = contador

    # Calcula a média dos vetores
    jal ra, media         # Chama a função media para o primeiro vetor
    mv s3, a0             # s3 = média do primeiro vetor
    jal ra, media         # Chama a função media para o segundo vetor
    mv s4, a0             # s4 = média do segundo vetor

    # Calcula a covariância
    loop_v:
        lw t2, 0(s10)         # t2 = próximo elemento do primeiro vetor
        lw t3, 0(s1)          # t3 = próximo elemento do segundo vetor
        sub t2, t2, s3        # t2 = xi - média_x
        sub t3, t3, s4        # t3 = yi - média_y
        mul t2, t2, t3        # t2 = (xi - média_x) * (yi - média_y)
        add t0, t0, t2        # Adiciona o produto à soma dos produtos
        addi s10, s10, 4      # Avança para o próximo elemento do primeiro vetor
        addi s1, s1, 4        # Avança para o próximo elemento do segundo vetor
        addi t1, t1, 1        # Incrementa o contador
        bne t1, s2, loop_cov  # Verifica se todos os elementos foram processados

    div t0, t0, s2        # Calcula a covariância: soma dos produtos / quantidade - 1

    mv a0, t0             # Coloca o resultado (covariância) em a0

    lw s10, 0(sp)         # Restaura s10
    lw s1, 4(sp)          # Restaura s1
    lw s2, 8(sp)          # Restaura s2
    lw s3, 12(sp)         # Restaura s3
    lw s4, 16(sp)         # Restaura s4
    lw s5, 20(sp)         # Restaura s5
    lw t0, 24(sp)         # Restaura t0
    lw t1, 28(sp)         # Restaura t1
    addi sp, sp, 32       # Libera espaço na pilha
    jr ra                 # Retorna
    
##### R2 END MODIFIQUE AQUI END #####
FIM: add t0, zero, s0