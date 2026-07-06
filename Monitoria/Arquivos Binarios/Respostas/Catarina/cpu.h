#ifndef _CPU_H
#define _CPU_H

#include <stdlib.h>
#include <stdio.h>
#include "instrucao.h"

/**
 * @brief Estrutura abstrata que representa a CPU.
 * 
 * A CPU é responsável por:
 * - Manter 8 registradores internos.
 * - Ler instruções a partir de um arquivo binário.
 * - Executar instruções matemáticas sobre os registradores.
 */
typedef struct cpu Cpu;

/**
 * @brief Cria e inicializa uma CPU.
 * 
 * A CPU criada deve possuir 8 registradores, que posteriormente
 * serão inicializados com valores lidos do arquivo binário.
 * 
 * @return Ponteiro para a CPU criada e alocada dinamicamente.
 */
Cpu *criaCpu();

/**
 * @brief Lê e executa um conjunto de instruções a partir de um arquivo binário.
 * 
 * Essa função lê as instruções armazenadas no arquivo e as executa
 * sequencialmente na CPU.
 * 
 * @param c CPU que executará as instruções.
 * @param f Arquivo binário de onde as instruções serão lidas.
 * @param nInstrucoes Quantidade de instruções a serem executadas.
 */
void realizaInstrucao(Cpu *c, FILE *f, int nInstrucoes);

/**
 * @brief Executa uma única instrução na CPU.
 * 
 * A instrução é interpretada e aplicada sobre os registradores da CPU,
 * substituindo o valor do registrador de destino pelo resultado da operação.
 * 
 * @param c CPU que executará a instrução.
 * @param i Instrução a ser executada.
 */
void executaInstrucao(Cpu *c, Instrucao *i);

/**
 * @brief Imprime o conteúdo dos 8 registradores da CPU.
 * 
 * Os registradores são impressos em ordem, do registrador 0 ao 7.
 * 
 * @param c CPU cujos registradores serão impressos.
 */
void imprimeRegistradores(Cpu *c);

/**
 * @brief Libera toda a memória associada à CPU.
 * 
 * @param c CPU a ser liberada.
 */
void liberaCpu(Cpu *c);

#endif
