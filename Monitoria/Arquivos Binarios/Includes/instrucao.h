#ifndef _INSTRUCAO_H
#define _INSTRUCAO_H

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Estrutura abstrata que representa uma instrução matemática.
 * 
 * Cada instrução contém:
 * - Um opcode que define a operação (A, S, M ou D).
 * - Um registrador de destino.
 * - Dois registradores de origem.
 */
typedef struct instrucao Instrucao;

/**
 * @brief Cria e inicializa uma instrução.
 * 
 * @return Ponteiro para a instrução criada e alocada dinamicamente.
 */
Instrucao *criaInstrucao();

/**
 * @brief Escreve uma instrução em um arquivo binário.
 * 
 * @param i Instrução a ser escrita.
 * @param f Arquivo binário onde a instrução será armazenada.
 */
void escreveInstrucaoArquivo(Instrucao *i, FILE *f);

/**
 * @brief Lê uma instrução de um arquivo binário.
 * 
 * @param f Arquivo binário de onde a instrução será lida.
 * @return Ponteiro para a instrução lida e alocada dinamicamente.
 */
Instrucao *leInstrucaoArquivo(FILE *f);

/**
 * @brief Retorna o opcode da instrução.
 * 
 * @param i Instrução analisada.
 * @return Caractere que representa a operação da instrução.
 */
char getOpcode(Instrucao *i);

/**
 * @brief Retorna o índice do registrador de destino.
 * 
 * @param i Instrução analisada.
 * @return Índice do registrador de destino.
 */
int getIndiceRegDestino(Instrucao *i);

/**
 * @brief Retorna o índice do primeiro registrador de origem.
 * 
 * @param i Instrução analisada.
 * @return Índice do primeiro registrador de origem.
 */
int getIndiceReg1(Instrucao *i);

/**
 * @brief Retorna o índice do segundo registrador de origem.
 * 
 * @param i Instrução analisada.
 * @return Índice do segundo registrador de origem.
 */
int getIndiceReg2(Instrucao *i);

#endif
