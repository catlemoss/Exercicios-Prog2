#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura abstrata que representa o Usuário do sistema.
 * 
 * O Usuário é responsável por:
 * - Ler dados da entrada padrão.
 * - Criar instruções matemáticas.
 * - Escrever os dados no arquivo binário.
 */
struct usuario
{
    int nInst;
};

/**
 * @brief Cria e inicializa um usuário.
 * 
 * @param nInstrucoes Número de instruções que o usuário irá fornecer.
 * @return Ponteiro para o usuário criado e alocado dinamicamente.
 */
Usuario *criaUsuario(int nInstrucoes)
{
    Usuario *u = malloc (sizeof (Usuario));
    if (u == NULL) exit (1);

    u->nInst = nInstrucoes;

    return u;
}

/**
 * @brief Lê uma instrução da entrada padrão e a grava no arquivo binário.
 * 
 * @param u Usuário que está fornecendo a instrução.
 * @param f Arquivo binário onde a instrução será escrita.
 */
void adicionaInstrucao(Usuario *u, FILE *f)
{
    for (int j = 0; j < u->nInst; j++)
    {
        Instrucao *i = criaInstrucao();
        escreveInstrucaoArquivo(i, f);
        free(i);
    }
}

/**
 * @brief Libera toda a memória associada ao usuário.
 * 
 * @param u Usuário a ser liberado.
 */
void liberaUsuario(Usuario *u)
{
    free (u);
}