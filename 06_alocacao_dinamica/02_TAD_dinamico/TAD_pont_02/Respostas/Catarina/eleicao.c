#include <stdio.h>
#include <stdlib.h>

#include "eleicao.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct {
    tCandidato** presidentes;
    int totalPresidentes;

    tCandidato** governadores;
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor** eleitores;
    int totalEleitores;
    
} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando as variáveis que armazenam votos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados
 * A memória necessária para os vetores "presidentes", "governadores" deve ser alocada aqui.
 * Demais ponteiros devem ser inicializado com NULL.
 * @return Eleição inicializada.
 */
tEleicao* InicializaEleicao()
{
    tEleicao *e = calloc (1, sizeof(*e));
    if (e == NULL) exit (1);

    e->presidentes = malloc (MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato));
    e->governadores = malloc (MAX_CANDIDATOS_POR_CARGO * sizeof(tCandidato));

    int nCand;
    scanf("%d\n", &nCand);

    for (int i = 0; i < nCand; i++)
    {
        tCandidato *c = CriaCandidato();
        LeCandidato(c);

        if (EhMesmoCandidato(e->presidentes[i], c) || EhMesmoCandidato(e->governadores[i], c))
        {
            ApagaCandidato(c);
            return;
        }

        if (ObtemCargo(c) == 'P')
        {
            e->presidentes[i] = c;
            e->totalPresidentes++;
        }

        else 
        {
            e->governadores[i] = c;
            e->totalGovernadores++;
        }
    }

    return e;
}


void ApagaEleicao(tEleicao* eleicao)
{
    for (int i = 0; i < eleicao->totalPresidentes; i++)
    {
        ApagaCandidato(eleicao->presidentes[i]);
    }

    free (eleicao->presidentes);

    for (int i = 0; i < eleicao->totalGovernadores; i++)
    {
        ApagaCandidato(eleicao->governadores[i]);
    }

    free (eleicao->governadores);

    for (int i = 0; i < eleicao->totalEleitores; i++)
    {
        ApagaCandidato(eleicao->eleitores[i]);
    }

    free (eleicao->eleitores);

    free (eleicao);
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada. 
 */
void RealizaEleicao(tEleicao* eleicao)
{
    int nEleitores;
    scanf("%d\n", &nEleitores);

    eleicao->eleitores = malloc (MAX_ELEITORES * sizeof(tEleitor));

    for (int i = 0; i < nEleitores; i++)
    {
        tEleitor *e = CriaEleitor();
        LeEleitor(e);

        if (EhMesmoEleitor(eleicao->eleitores[i], e))
        {
            ApagaEleitor(e);
            return;
        }

        eleicao->eleitores[i] = e;
        eleicao->totalEleitores++;

        if (ObtemVotoPresidente(e) == 0)
        {
            eleicao->votosBrancosPresidente++;
        }
        else if (ObtemVotoPresidente(e) == -1)
        {
            eleicao->votosNulosPresidente++;
        }

        if (ObtemVotoGovernador(e) == 0)
        {
            eleicao->votosBrancosGovernador++;
        }
        else if (ObtemVotoGovernador(e) == -1)
        {
            eleicao->votosNulosGovernador++;
        }
    }
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao* eleicao)
{
}