#include "instrucao.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura abstrata que representa uma instrução matemática.
 * 
 * Cada instrução contém:
 * - Um opcode que define a operação (A, S, M ou D).
 * - Um registrador de destino.
 * - Dois registradores de origem.
 */
struct instrucao
{
    char opcode;
    int rDest;
    int rOrig1;
    int rOrig2;
};

/**
 * @brief Cria e inicializa uma instrução.
 * 
 * @return Ponteiro para a instrução criada e alocada dinamicamente.
 */
Instrucao *criaInstrucao()
{
    Instrucao *i = malloc (sizeof (Instrucao));
    if (i == NULL) exit (1);

    scanf(" %c %d %d %d", 
        &i->opcode, 
        &i->rDest, 
        &i->rOrig1, 
        &i->rOrig2
    );

    return i;
}

/**
 * @brief Escreve uma instrução em um arquivo binário.
 * 
 * @param i Instrução a ser escrita.
 * @param f Arquivo binário onde a instrução será armazenada.
 */
void escreveInstrucaoArquivo(Instrucao *i, FILE *f)
{
    fwrite (&i->opcode, sizeof(char), 1, f);
    fwrite (&i->rDest, sizeof(int), 1, f);
    fwrite (&i->rOrig1, sizeof(int), 1, f);
    fwrite (&i->rOrig2, sizeof(int), 1, f);
}

/**
 * @brief Lê uma instrução de um arquivo binário.
 * 
 * @param f Arquivo binário de onde a instrução será lida.
 * @return Ponteiro para a instrução lida e alocada dinamicamente.
 */
Instrucao *leInstrucaoArquivo(FILE *f)
{
    Instrucao *i = malloc (sizeof (Instrucao));
    if (i == NULL) exit (1);
    
    fread (&i->opcode, sizeof(char), 1, f);
    fread (&i->rDest, sizeof(int), 1, f);
    fread (&i->rOrig1, sizeof(int), 1, f);
    fread (&i->rOrig2, sizeof(int), 1, f);

    return i;
}

/**
 * @brief Retorna o opcode da instrução.
 * 
 * @param i Instrução analisada.
 * @return Caractere que representa a operação da instrução.
 */
char getOpcode(Instrucao *i)
{
    return i->opcode;
}

/**
 * @brief Retorna o índice do registrador de destino.
 * 
 * @param i Instrução analisada.
 * @return Índice do registrador de destino.
 */
int getIndiceRegDestino(Instrucao *i)
{
    return i->rDest;
}

/**
 * @brief Retorna o índice do primeiro registrador de origem.
 * 
 * @param i Instrução analisada.
 * @return Índice do primeiro registrador de origem.
 */
int getIndiceReg1(Instrucao *i)
{
    return i->rOrig1;
}

/**
 * @brief Retorna o índice do segundo registrador de origem.
 * 
 * @param i Instrução analisada.
 * @return Índice do segundo registrador de origem.
 */
int getIndiceReg2(Instrucao *i)
{
    return i->rOrig2;
}
