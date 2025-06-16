#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    printf("--------------------POXIM-V--------------------\n");
    // abertura dos arquivos de entrada e saída
	FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");

    // FILE* input = fopen("input.hex", "r");
    // FILE* output = fopen("output.out", "w");

    printf("Entrada e saída lidos com sucesso!\n");

    
    // endereço inicial da memória
    const uint32_t endereco_inicial = 0x80000000;
    
    // array dos registradores e seus nomes
    uint32_t reg[32] = {0};
    const char* reg_nomes[32] = {
        "zero", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
        "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
        "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
        "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

    // criação do pc inicializando em endereco_inicial
    uint32_t pc = endereco_inicial;

    // criação de array para memória
    uint8_t* mem = (uint8_t*)(malloc(32 * 1024));
    if (mem == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // ENTRADA
    // lê os bytes e armazena na memória
    uint32_t endereco_atual = endereco_inicial;
    char linha[76];
    
    while (fgets(linha, sizeof(linha), input)) {
        if (linha[0] == '@') {
            endereco_atual = (uint32_t) strtol(linha + 1, NULL, 16);
        }
        else {
            unsigned int byte;
            int index = 0;
            while (sscanf(linha + index, "%2x", &byte) == 1) {
                mem[endereco_atual - endereco_inicial] = (uint8_t) byte;
                endereco_atual++;
                index += 3;
                if (linha[index] == '\0' || linha[index] == '\n') break;
            }
        }
    }
    
    printf("Memória alocada com sucesso!\n");
    
    uint8_t run = 1;

    while (run) {
        // leitura da instrução na memória
        // instruction é o valor de 4 bytes no endereço de pc
        uint32_t instruction = ((uint32_t*) mem)[(pc - endereco_inicial) >> 2];

        // leitura do opcode (últimos 7 bits)
        uint8_t opcode = instruction & 0b1111111;
        // leitura do campo rd (bits de 7 a 11))
        uint8_t rd = (instruction & (0b11111 << 7)) >> 7;
        // leitura do campo funct3 (bits de 12 a 15)
        uint8_t funct3 = (instruction & (0b111 << 12)) >> 12;
        // leitura do campo rs1 (bits de 15 a 20)
        uint8_t rs1 = (instruction & (0b11111 << 15)) >> 15;
        // leitura do campo rs2 (bits de 20 a 24)
        uint8_t rs2 = (instruction & (0b11111 << 20)) >> 20;
        // leitura do campo funct7 (bits de 25 a 31)
        uint8_t funct7 = instruction >> 25;
        // leitura do campo imm com sinal (12 bits)
        int32_t imm_i = ((int32_t)(instruction)) >> 20;
        // leitura do campo imm sem sinal (12 bits)
        // uint32_t imm_u = (instruction >> 20) & 0xFFF;
        // leitura do imm S-type
        /* O imediato de 12 bits está dividido em duas partes: 
        instruction[31:25] = 7 bits
        instruction[11:7] = 5 bits 
        sign extension: Se o bit 11 for 1, todos os outros viram 1 tbm */
        int32_t imm_s = (((instruction >> 25) & 0x7F) << 5) | ((instruction >> 7) & 0x1F);
        if (imm_s & 0x800) imm_s |= 0xFFFFF000;
        // leitura do imm B-type
        int32_t imm_b = ((instruction >> 31) & 0x1) << 12 |
                ((instruction >> 7)  & 0x1) << 11 |
                ((instruction >> 25) & 0x3F) << 5 |
                ((instruction >> 8)  & 0xF) << 1;
                if (imm_b & 0x1000) imm_b |= 0xFFFFE000;
        // leitura do imm J-type
        int32_t imm_j = 0;
        imm_j |= ((instruction >> 31) & 0x1) << 20;    
        imm_j |= ((instruction >> 21) & 0x3FF) << 1;   
        imm_j |= ((instruction >> 20) & 0x1) << 11;    
        imm_j |= ((instruction >> 12) & 0xFF) << 12;   
        if (imm_j & (1 << 20)) imm_j |= 0xFFF00000; 

        switch (opcode) {
            case 0b0110011:
                // instruções R-type
                // operação add
                // Soma o conteúdo de dois registradores (rs1 e rs2) e armazena o resultado no registrador rd
                if (funct3 == 0b000 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] + reg[rs2];

                    fprintf(output, "0x%08x:add    %s,%s,%s     %s=0x%08x+0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2], reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    // registrador zero (x0) nunca é modificado
                    if (rd != 0) reg[rd] = valor;
                }
                // operação sub
                // Subtrai o conteúdo do registrador rs2 do registrador rs1 e armazena o resultado no registrador rd
                else if (funct3 == 0b000 && funct7 == 0b0100000) {
                    uint32_t valor = reg[rs1] - reg[rs2];

                    fprintf(output, "0x%08x:sub    %s,%s,%s     %s=0x%08x-0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação sll
                /* Desloca os bits do registrador rs1 para a esquerda, em um número de posições indicado pelos 5 bits
                menos significativos do registrador rs2. O resultado é armazenado no registrador rd */ 
                else if (funct3 == 0b001 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] << (reg[rs2] & 0x1F);

                    fprintf(output, "0x%08x:sll    %s,%s,%s     %s=0x%08x<<%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2] & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação slt
                /* Compara os valores de rs1 e rs2 como inteiros com sinal.
                Se rs1 < rs2, então rd = 1. Caso contrário, rd = 0. */
                else if (funct3 == 0b010 && funct7 == 0b0000000) {
                    uint32_t valor = ((int32_t) reg[rs1] < (int32_t) reg[rs2]) ? 1 : 0;

                    fprintf(output, "0x%08x:slt    %s,%s,%s     %s=(0x%08x<0x%08x)=%u\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);
                    
                    if (rd != 0) reg[rd] = valor;
                }
                // operação sltu
                /* Compara os valores de rs1 e rs2 como inteiros sem sinal.
                Se rs1 < rs2, então rd = 1. Caso contrário, rd = 0. */
                else if (funct3 == 0b011 && funct7 == 0b0000000) {
                    uint32_t valor = (reg[rs1] < reg[rs2]) ? 1 : 0;

                    fprintf(output, "0x%08x:sltu   %s,%s,%s     %s=(0x%08x<0x%08x)=%u\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação xor
                /* Realiza a operação bit a bit XOR entre os valores dos registradores rs1 e rs2, e armazena o resultado em rd. */
                else if (funct3 == 0b100 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] ^ reg[rs2];

                    fprintf(output, "0x%08x:xor    %s,%s,%s     %s=0x%08x^0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação srl
                /* Desloca os bits do registrador rs1 para a direita, em um número de posições indicado pelos 5 bits
                menos significativos do registrador rs2. O resultado é armazenado no registrador rd. */
                else if (funct3 == 0b101 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] >> (reg[rs2] & 0x1F);

                    fprintf(output, "0x%08x:srl    %s,%s,%s     %s=0x%08x>>%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2] & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação sra
                /*Desloca os bits do registrador rs1 para a direita, em um número de posições indicado pelos 5 bits
                menos significativos do registrador rs2. Mas, diferente do srl (shift lógico), o sra mantém o bit de sinal. */
                else if (funct3 == 0b101 && funct7 == 0b0100000) {
                    uint32_t valor = (uint32_t)(((int32_t) reg[rs1]) >> (reg[rs2] & 0x1F));

                    fprintf(output, "0x%08x:sra    %s,%s,%s     %s=0x%08x>>>%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2] & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação or
                /* Realiza a operação bit a bit OR entre os valores dos registradores rs1 e rs2, e armazena o resultado em rd. */
                else if (funct3 == 0b110 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] | reg[rs2];

                    fprintf(output, "0x%08x:or     %s,%s,%s     %s=0x%08x|0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação and
                /* Realiza a operação bit a bit AND entre os valores dos registradores rs1 e rs2, e armazena o resultado em rd. */
                else if (funct3 == 0b111 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] & reg[rs2];

                    fprintf(output, "0x%08x:and    %s,%s,%s     %s=0x%08x&0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação mul
                else if (funct3 == 0b000 && funct7 == 0b0000001) {
                    uint32_t valor = reg[rs1] * reg[rs2];

                    fprintf(output, "0x%08x:mul    %s,%s,%s     %s=0x%08x*0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação mulh
                // Multiplica com sinal rs1 e rs2. Retorna a parte alta dos 64 bits de resultado.
                else if (funct3 == 0b001 && funct7 == 0b0000001) {
                    int64_t calculo = (int64_t)(int32_t)reg[rs1] * (int64_t)(int32_t)reg[rs2];
                    uint32_t valor = (uint32_t)(calculo >> 32); 

                    fprintf(output, "0x%08x:mulh   %s,%s,%s     %s=0x%08x*0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação mulhsu
                // Multiplica rs1 como signed e rs2 como unsigned. Retorna a parte alta dos 64 bits de resultado.
                else if (funct3 == 0b010 && funct7 == 0b0000001) {
                    int64_t calculo = (int64_t)(int32_t)reg[rs1] * (uint64_t)reg[rs2];
                    uint32_t valor = (uint32_t)(calculo >> 32);

                    fprintf(output, "0x%08x:mulhsu %s,%s,%s     %s=0x%08x*0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação mulhu
                // Multiplica rs1 e rs2 como unsigned.
                else if (funct3 == 0b011 && funct7 == 0b0000001) {
                    uint64_t calculo = (uint64_t)reg[rs1] * (uint64_t)reg[rs2];
                    uint32_t valor = (uint32_t)(calculo >> 32);

                    fprintf(output, "0x%08x:mulhu  %s,%s,%s     %s=0x%08x*0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação div
                else if (funct3 == 0b100 && funct7 == 0b0000001) {
                    int32_t valor;
                    if (reg[rs2] == 0) {
                        valor = -1;
                    }
                    else {
                        valor = (int32_t)reg[rs1] / (int32_t) reg[rs2];
                    }

                    fprintf(output, "0x%08x:div    %s,%s,%s     %s=0x%08x/0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação divu
                else if (funct3 == 0b101 && funct7 == 0b0000001) {
                    uint32_t valor;

                    if (reg[rs2] == 0) {
                        valor = 0xFFFFFFFF;
                    } else {
                        valor = reg[rs1] / reg[rs2];
                    }

                    fprintf(output, "0x%08x:divu   %s,%s,%s     %s=0x%08x/0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação rem
                else if (funct3 == 0b110 && funct7 == 0b0000001) {
                    int32_t valor;

                    if (reg[rs2] == 0) {
                        valor = reg[rs1];
                    } 
                    else {
                        valor = (int32_t)reg[rs1] % (int32_t)reg[rs2];
                    }

                    fprintf(output, "0x%08x:rem    %s,%s,%s     %s=0x%08x%%0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação remu
                else if (funct3 == 0b111 && funct7 == 0b0000001) {
                    uint32_t valor;

                    if (reg[rs2] == 0) {
                        valor = reg[rs1];
                    } 
                    else {
                        valor = reg[rs1] % reg[rs2];
                    }

                    fprintf(output, "0x%08x:remu    %s,%s,%s     %s=0x%08x%%0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], reg_nomes[rs2],
                            reg_nomes[rd], reg[rs1], reg[rs2], valor);

                    if (rd != 0) reg[rd] = valor;
                }
                break;
            case 0b0010011:
                // instruções I-type
                // operação addi
                /* Soma um valor imediato (constante) de 12 bits, sinalizado, ao conteúdo do registrador rs1 e armazena o resultado em rd */
                if (funct3 == 0b000) {
                    uint32_t valor = reg[rs1] + imm_i;

                    fprintf(output, "0x%08x:addi   %s,%s,0x%03x     %s=0x%08x+0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], (uint16_t)(imm_i & 0xFFF), reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação andi
                /* and bit a bit com valor imediato e com sinal. */
                else if (funct3 == 0b111) {
                    uint32_t valor = reg[rs1] & imm_i;

                    fprintf(output, "0x%08x:andi   %s,%s,%03x   %s=0x%08x&0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i, reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação ori
                /* or bit a bit com valor imediato e com sinal. */
                else if (funct3 == 0b110) {
                    uint32_t valor = reg[rs1] | imm_i;

                    fprintf(output, "0x%08x:ori    %s,%s,%03x   %s=0x%08x|0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i, reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação xori
                /* xor bit a bit com valor imediato e com sinal. */
                else if (funct3 == 0b100) {
                    uint32_t valor = reg[rs1] ^ imm_i;

                    fprintf(output, "0x%08x:xori   %s,%s,%03x   %s=0x%08x^0x%08x=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i, reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação sltiu
                /* Compara o registrador rs1 com o imediato (imm) como valores sem sinal. */
                else if (funct3 == 0b011) {
                    uint32_t valor = (reg[rs1] < imm_i) ? 1 : 0;

                    fprintf(output, "0x%08x:sltiu  %s,%s,0x%03x   %s=(0x%08x<0x%08x)=%u\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i, reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação slti
                /* Compara o registrador rs1 com o imediato (imm) como valores com sinal. */
                else if (funct3 == 0b010) {
                    uint32_t valor = ((int32_t)reg[rs1] < imm_i) ? 1 : 0;

                    fprintf(output, "0x%08x:slti   %s,%s,%03x   %s=(0x%08x<0x%08x)=%u\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i, reg_nomes[rd], reg[rs1], imm_i, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação slli
                /* desloca os bits do registrador rs1 para a esquerda, por um número de posições indicado no campo imediato */
                else if (funct3 == 0b001 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] << ((instruction >> 20) & 0x1F);
      
                    fprintf(output, "0x%08x:slli   %s,%s,%u      %s=0x%08x<<%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], (instruction >> 20) & 0x1F,
                            reg_nomes[rd], reg[rs1], (instruction >> 20) & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação srli
                /* Desloca os bits do registrador rs1 para a direita, por um número de posições indicado pelo imediato */
                else if (funct3 == 0b101 && funct7 == 0b0000000) {
                    uint32_t valor = reg[rs1] >> ((instruction >> 20) & 0x1F);

                    fprintf(output, "0x%08x:srli   %s,%s,%u      %s=0x%08x>>%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], (instruction >> 20) & 0x1F,
                            reg_nomes[rd], reg[rs1], (instruction >> 20) & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                // operação srai
                /* desloca os bits do registrador rs1 para a direita, por um número de posições indicado pelo imediato.
                O deslocamento é aritmético, ou seja, preserva o bit de sinal */
                else if (funct3 == 0b101 && funct7 == 0b0100000) {
                    uint32_t valor = (uint32_t)(((int32_t)reg[rs1]) >> ((instruction >> 20) & 0x1F));

                    fprintf(output, "0x%08x:srai   %s,%s,%u      %s=0x%08x>>%u=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], (instruction >> 20) & 0x1F,
                            reg_nomes[rd], reg[rs1], (instruction >> 20) & 0x1F, valor);

                    if (rd != 0) reg[rd] = valor;
                }
                break;
            case 0b0000011:
                // instruções load
                // operação lb
                /* Carrega 1 byte com sinal da memória para um registrador. */
                if (funct3 == 0b000) {
                    uint32_t endereco = reg[rs1] + imm_i;
                    int8_t valor = (int8_t) mem[endereco - endereco_inicial];

                    if (rd != 0) reg[rd] = (int32_t) valor;

                    fprintf(output, "0x%08x:lb     %s,0x%03x(%s)  %s=mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rd], imm_i & 0xFFF, reg_nomes[rs1],
                            reg_nomes[rd], endereco, reg[rd]);
                }
                // operação lh
                /* Carrega 2 bytes (16 bits) da memória para um registrador. */
                else if (funct3 == 0b001) {
                    uint32_t endereco = reg[rs1] + imm_i;
                    int16_t valor = (int16_t)(
                        mem[endereco - endereco_inicial] | (mem[endereco - endereco_inicial + 1] << 8));

                    if (rd != 0) reg[rd] = (int32_t) valor;

                    fprintf(output, "0x%08x:lh     %s,0x%03x(%s)  %s=mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rd], imm_i & 0xFFF, reg_nomes[rs1],
                            reg_nomes[rd], endereco, reg[rd]);
                }
                // operação lw
                /* Carrega 4 bytes (32 bits) da memória para um registrador. */
                else if (funct3 == 0b010) {
                    uint32_t endereco = (reg[rs1] + (int32_t)imm_i) - endereco_inicial;

                    uint32_t valor = mem[endereco] |
                                    (mem[endereco + 1] << 8) |
                                    (mem[endereco + 2] << 16) |
                                    (mem[endereco + 3] << 24);

                    if (rd != 0) reg[rd] = valor;

                    fprintf(output, "0x%08x:lw     %s,%03x(%s)  %s=mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rd], (int32_t)imm_i, reg_nomes[rs1],
                            reg_nomes[rd], reg[rs1] + (int32_t)imm_i, valor);
                }
                // operação lbureg[rs1] + imm_i]
                /* Carrega 1 byte (8 bits) da memória e zero-extende para 32 bits. */
                else if (funct3 == 0b100) {
                    uint32_t endereco = reg[rs1] + imm_i;
                    uint8_t valor = (uint8_t) mem[endereco - endereco_inicial];

                    if (rd != 0) reg[rd] = (uint32_t) valor;

                    fprintf(output, "0x%08x:lbu    %s,0x%03x(%s)  %s=mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rd], imm_i & 0xFFF, reg_nomes[rs1],
                            reg_nomes[rd], endereco, reg[rd]);
                }
                // operação lhu
                /* Carrega 2 bytes (16 bits) da memória e zero-extende para 32 bits. */
                else if (funct3 == 0b101) {
                    uint32_t endereco = reg[rs1] + imm_i;
                    uint16_t valor = (mem[endereco - endereco_inicial] | (mem[endereco - endereco_inicial+ 1] << 8));

                    if (rd != 0) reg[rd] = (uint32_t) valor;

                    fprintf(output, "0x%08x:lhu    %s,0x%03x(%s)  %s=mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rd], imm_i & 0xFFF, reg_nomes[rs1],
                            reg_nomes[rd], reg[rs1] + imm_i, reg[rd]);
                }
                break;
            case 0b0100011:
                // instruções store
                // operação sb
                /* Armazena o byte menos significativo do registrador rs2 na memória. */
                if (funct3 == 0b000) {
                    uint8_t valor = (uint8_t)(reg[rs2] & 0xFF);
                    mem[reg[rs1] + imm_s - endereco_inicial] = valor;

                    fprintf(output, "0x%08x:sb     %s,0x%03x(%s) mem[0x%08x]=0x%02x\n",
                            pc, reg_nomes[rs2], imm_s & 0xFFF, reg_nomes[rs1],
                            reg[rs1] + imm_s, valor);
                }
                // operação sh
                /* Armazena os 16 bits menos significativos do registrador rs2 na memória. */
                else if (funct3 == 0b001) {
                    uint16_t valor = (uint16_t)(reg[rs2] & 0xFFFF);
                    mem[reg[rs1] + imm_s - endereco_inicial] = valor & 0xFF;
                    mem[reg[rs1] + imm_s + 1 - endereco_inicial] = (valor >> 8) & 0xFF;

                    fprintf(output, "0x%08x:sh     %s,0x%03x(%s) mem[0x%08x]=0x%04x\n",
                            pc, reg_nomes[rs2], imm_s & 0xFFF, reg_nomes[rs1],
                            reg[rs1] + imm_s, valor);
                }
                // operação sw
                /* Armazena 32 bits completos do registrador rs2 na memória. */
                else if (funct3 == 0b010) {
                    uint32_t valor = reg[rs2];
                    mem[reg[rs1] + imm_s - endereco_inicial] = valor & 0xFF;
                    mem[reg[rs1] + imm_s - endereco_inicial + 1] = (valor >> 8) & 0xFF;
                    mem[reg[rs1] + imm_s - endereco_inicial + 2] = (valor >> 16) & 0xFF;
                    mem[reg[rs1] + imm_s - endereco_inicial + 3] = (valor >> 24) & 0xFF;

                    fprintf(output, "0x%08x:sw     %s,0x%03x(%s) mem[0x%08x]=0x%08x\n",
                            pc, reg_nomes[rs2], imm_s & 0xFFF, reg_nomes[rs1],
                            reg[rs1] + imm_s, valor);
                }
                break;
            case 0b1100011:
                // instruções branch
                // operação beq
                // Se reg[rs1] == reg[rs2], desvia (pc = pc + imm_b). Caso contrário, segue para próxima (pc = pc + 4)
                if (funct3 == 0b000) {
                    if (reg[rs1] == reg[rs2]) {
                        fprintf(output, "0x%08x:beq    %s,%s,0x%03x  (0x%08x==0x%08x)=%u->pc=0x%08x\n",
                            pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                            reg[rs1], reg[rs2], reg[rs1] == reg[rs2], pc + imm_b);
                        
                        pc = pc + imm_b;
                        continue;
                    }
                    else {
                        fprintf(output, "0x%08x:beq    %s,%s,0x%03x  (0x%08x==0x%08x)=%u->pc=0x%08x\n",
                            pc, reg_nomes[rs1], reg_nomes[rs2], imm_b+6,
                            reg[rs1], reg[rs2], reg[rs1] == reg[rs2], pc + 4);
                    }
                }
                // operação bne
                // Desvia (pc = pc + imm_b) se o conteúdo de rs1 for diferente do conteúdo de rs2.
                else if (funct3 == 0b001) {
                    if (reg[rs1] != reg[rs2]) {
                        fprintf(output, "0x%08x:bne    %s,%s,0x%03x  (0x%08x!=0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], reg[rs1] != reg[rs2], pc + imm_b);
                                
                        pc += imm_b;
                        continue;
                    }
                    else {
                        fprintf(output, "0x%08x:bne    %s,%s,0x%03x  (0x%08x!=0x%08x)=%u->pc=0x%08x\n",
                            pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                            reg[rs1], reg[rs2], reg[rs1] != reg[rs2], pc + 4);
                    }
                }
                // operação blt
                /* Desvia (pc = pc + imm_b) se o conteúdo de rs1 for menor que o de rs2 (comparação com sinal).*/
                else if (funct3 == 0b100) {
                    if ((int32_t)reg[rs1] < (int32_t)reg[rs2]) {
                        fprintf(output, "0x%08x:blt    %s,%s,0x%03x         (0x%08x<0x%08x)=1->pc=0x%08x\n",
                            pc, reg_nomes[rs1], reg_nomes[rs2], ((imm_b+4) & 0xFFF),
                            reg[rs1], reg[rs2], pc + imm_b);
                                
                        pc += imm_b;
                        continue;
                    } 
                    else { 
                        fprintf(output, "0x%08x:blt    %s,%s,0x%03x         (0x%08x<0x%08x)=0->pc=0x%08x\n",
                            pc, reg_nomes[rs1], reg_nomes[rs2], ((imm_b+4) & 0xFFF),
                            reg[rs1], reg[rs2], pc + 4);
                    }
                }
                // operação bge
                // Desvia (pc = pc + imm_b) se o conteúdo de rs1 for maior ou igual ao de rs2 (comparação com sinal).
                else if (funct3 == 0b101) {
                    if ((int32_t)reg[rs1] >= (int32_t)reg[rs2]) {
                        fprintf(output, "0x%08x:bge    %s,%s,0x%03x  (0x%08x>=0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], (int32_t)reg[rs1] >= (int32_t)reg[rs2], pc + imm_b);
                                
                        pc += imm_b;
                        continue;
                    }
                    else {
                        fprintf(output, "0x%08x:bge    %s,%s,0x%03x  (0x%08x>=0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], (int32_t)reg[rs1] >= (int32_t)reg[rs2], pc + 4);
                    }
                }
                // operação bltu
                else if (funct3 == 0b110) {
                    if (reg[rs1] < reg[rs2]) {
                        fprintf(output, "0x%08x:bltu   %s,%s,0x%03x  (0x%08x<0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], reg[rs1] < reg[rs2], pc + imm_b);
                        pc += imm_b;
                        continue;
                    } else {
                        fprintf(output, "0x%08x:bltu   %s,%s,0x%03x  (0x%08x<0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], reg[rs1] < reg[rs2], pc + 4);
                    }
                }
                // operação bgeu
                else if (funct3 == 0b111) {
                    if (reg[rs1] >= reg[rs2]) {
                        fprintf(output, "0x%08x:bgeu   %s,%s,0x%03x  (0x%08x>=0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], reg[rs1] >= reg[rs2], pc + imm_b);
                        pc += imm_b;
                        continue;
                    } else {
                        fprintf(output, "0x%08x:bgeu   %s,%s,0x%03x  (0x%08x>=0x%08x)=%u->pc=0x%08x\n",
                                pc, reg_nomes[rs1], reg_nomes[rs2], imm_b,
                                reg[rs1], reg[rs2], reg[rs1] >= reg[rs2], pc + 4);
                    }
                }
                break;
            case 0b1101111:
                // operação jal
                // Salva (pc+4) em rd, depois PC = PC + imm_j
                    uint32_t next = pc + imm_j;
                    uint32_t returnPC = pc + 4;

                    fprintf(output, "0x%08x:jal    %s,0x%05x     pc=0x%08x,%s=0x%08x\n",
                            pc, reg_nomes[rd], (imm_j >> 1) & 0xFFFFF, next, reg_nomes[rd], returnPC);

                    if (rd != 0) reg[rd] = returnPC;
                    pc = next;
                    continue;
            case 0b1100111:
                // operação jalr
                if (funct3 == 0b000) {
                    uint32_t valor = (reg[rs1] + imm_i) & ~1; 
                    uint32_t returnPC = pc + 4;

                    fprintf(output, "0x%08x:jalr   %s,%s,0x%03x     pc=0x%08x+0x%08x,%s=0x%08x\n",
                            pc, reg_nomes[rd], reg_nomes[rs1], imm_i & 0xFFF,
                            reg[rs1], imm_i, reg_nomes[rd], returnPC);

                    if (rd != 0) reg[rd] = returnPC;
                    pc = valor;
                    continue;
                }
                break;
            case 0b0110111: {
                // operação lui
                // carrega um valor imediato de 20 bits na parte alta de um registrador, zerando os bits inferiores.
                uint32_t imm_u = instruction & 0xFFFFF000;

                fprintf(output, "0x%08x:lui    %s,0x%05x     %s=0x%08x\n",
                        pc, reg_nomes[rd], imm_u >> 12,reg_nomes[rd], imm_u);

                if (rd != 0) reg[rd] = imm_u;
                pc += 4;
                continue;
            }
            case 0b0010111: {
                // operação auipc
                // soma um valor imediato de 20 bits ao PC atual e armazena o resultado no registrador destino.
                uint32_t imm_u = instruction & 0xFFFFF000;
                uint32_t result = pc + imm_u;

                fprintf(output, "0x%08x:auipc  %s,0x%05x     %s=0x%08x+0x%05x000=0x%08x\n",
                        pc, reg_nomes[rd], imm_u >> 12, reg_nomes[rd], pc, imm_u >> 12, result);

                if (rd != 0) reg[rd] = result;
                pc += 4;
                continue;
            }
            case 0b1110011:
                // operação ebreak
                if (funct3 == 0b000 && imm_i == 1) {
                    fprintf(output, "0x%08x:ebreak\n", pc);
                    run = 0;
                }
                break;
            default:
                // saída para caso de erro
                fprintf(output, "Erro de execução");
                printf("Erro de execução em pc = 0x%08x!\n", pc);
                return 1;
        }
        // incremento de pc para o próximo endereço
        pc += 4;
    }
    
    printf("Poxim-V executado com sucesso!\n");
    printf("-----------------------------------------------\n");

    // fechando arquivos de entrada e saída
    fclose(input);
    fclose(output);
    free(mem);

    return 0;
}