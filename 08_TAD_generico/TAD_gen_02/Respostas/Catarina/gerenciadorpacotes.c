#include "gerenciadorpacotes.h"

#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qnt;
    int max;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador* CriaGerenciador()
{
    tGerenciador *g = malloc (sizeof (tGerenciador));
    if (g == NULL) return NULL;

    g->pacotes = NULL;
    g->qnt = 0;
    g->max = 0;

    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote 
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac)
{
    if (geren->max == 0)
    {
        geren->max = 4;
        geren->pacotes = malloc (geren->max * sizeof(tPacote *));
    }

    if (geren->qnt == geren->max)
    {
        int newMax = geren->max * 2;

        tPacote **newPac = realloc (geren->pacotes, newMax * sizeof (tPacote *));
        if (newPac == NULL) return;

        geren->max = newMax;
        geren->pacotes = newPac;
    }

    geren->pacotes[geren->qnt] = pac;
    geren->qnt++;
}


/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador* geren)
{
    for (int i = 0; i < geren->qnt; i++)
    {
        DestroiPacote (geren->pacotes[i]);
    }

    free (geren->pacotes);
    free (geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador* geren, int idx)
{
    for (int i = 0; i < geren->qnt; i++)
    {
        if (i == idx) ImprimePacote(geren->pacotes[i]);
    }
}


/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador* geren)
{
    for (int i = 0; i < geren->qnt; i++)
    {
        ImprimePacote(geren->pacotes[i]);
    }
}