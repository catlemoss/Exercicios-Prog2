#ifndef _USUARIO_H
#define _USUARIO_H

#include "instrucao.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Estrutura abstrata que representa o Usuário do sistema.
 * 
 * O Usuário é responsável por:
 * - Ler dados da entrada padrão.
 * - Criar instruções matemáticas.
 * - Escrever os dados no arquivo binário.
 */
typedef struct usuario Usuario;

/**
 * @brief Cria e inicializa um usuário.
 * 
 * @param nInstrucoes Número de instruções que o usuário irá fornecer.
 * @return Ponteiro para o usuário criado e alocado dinamicamente.
 */
Usuario *criaUsuario(int nInstrucoes);

/**
 * @brief Lê uma instrução da entrada padrão e a grava no arquivo binário.
 * 
 * @param u Usuário que está fornecendo a instrução.
 * @param f Arquivo binário onde a instrução será escrita.
 */
void adicionaInstrucao(Usuario *u, FILE *f);

/**
 * @brief Libera toda a memória associada ao usuário.
 * 
 * @param u Usuário a ser liberado.
 */
void liberaUsuario(Usuario *u);

#endif
