#include <stdio.h>
#include <string.h>

#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

tEleicao InicializaEleicao()
{
    tEleicao e;

    e.totalPresidentes = 0;
    e.totalGovernadores = 0;
    e.totalEleitores = 0;

    e.votosBrancosPresidente = 0;
    e.votosNulosPresidente = 0;

    e.votosBrancosGovernador = 0;
    e.votosNulosGovernador = 0;

    int nCandidatos;
    scanf("%d", &nCandidatos);

    for (int i = 0; i < nCandidatos; i++)
    {
        tCandidato c = LeCandidato();

        if (ObtemCargo(c) == 'P')
        {
            e.presidentes[e.totalPresidentes] = c;
            e.totalPresidentes++;
        }

        else if (ObtemCargo(c) == 'G')
        {                
            e.governadores[e.totalGovernadores] = c;
            e.totalGovernadores++;
        }
    }

    return e;
}

tEleicao RealizaEleicao(tEleicao eleicao)
{
    int nEleitores;
    scanf("%d", &nEleitores);

    for (int i = 0; i < nEleitores; i++)
    {
        tEleitor e = LeEleitor();

        if (eleicao.totalEleitores == MAX_ELEITORES)
        {
            eleicao.totalEleitores = -1;
            return eleicao;
        }

        for (int j = 0; j < eleicao.totalEleitores; j++)
        {
            if (EhMesmoEleitor(eleicao.eleitores[j], e))
            {
                eleicao.totalEleitores = -1;
                return eleicao;
            }
        }

        eleicao.eleitores[eleicao.totalEleitores] = e;
        eleicao.totalEleitores++;

        int votoP = ObtemVotoPresidente(e); // id 

        if (votoP == 0) eleicao.votosBrancosPresidente++;
        else 
        {
            int achou = 0;

            for (int j = 0; j < eleicao.totalPresidentes; j++)
            {
                if (VerificaIdCandidato(eleicao.presidentes[j], votoP)) // find id
                {
                    eleicao.presidentes[j] = 
                    IncrementaVotoCandidato(eleicao.presidentes[j]);

                    achou = 1;
                    break;
                }
            }

            if (!achou) eleicao.votosNulosPresidente++; // omg we do not have this id!
        }

        int votoG = ObtemVotoGovernador(e);

        if (votoG == 0) eleicao.votosBrancosGovernador++;
        else 
        {
            int achou = 0;

            for (int j = 0; j < eleicao.totalGovernadores; j++)
            {
                if (VerificaIdCandidato(eleicao.governadores[j], votoG))
                {
                    eleicao.governadores[j] = 
                    IncrementaVotoCandidato(eleicao.governadores[j]);

                    achou = 1;
                    break;
                }
            }

            if (!achou) eleicao.votosNulosGovernador++;
        }
    }

    return eleicao;
}

int IndiceMaisVotado(tCandidato candidatos[], int total)
{
    int indiceMaior = 0;

    for (int i = 1; i < total; i++)
    {
        if (ObtemVotos(candidatos[i]) > ObtemVotos(candidatos[indiceMaior]))
        {
            indiceMaior = i;
        }
    }

    return indiceMaior;
}

void ImprimeResultadoEleicao(tEleicao eleicao)
{
    if (eleicao.totalEleitores == -1)
    {
        printf("ELEICAO ANULADA\n");
        return;
    }
 
    int vencedorP = IndiceMaisVotado(eleicao.presidentes, eleicao.totalPresidentes);
    int vencedorG = IndiceMaisVotado(eleicao.governadores, eleicao.totalGovernadores);

    int invalidosP = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
    int invalidosG = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;

    int votosVencedorP = ObtemVotos(eleicao.presidentes[vencedorP]);
    int votosVencedorG = ObtemVotos(eleicao.governadores[vencedorG]);

    int totalVotosPresidente = eleicao.totalEleitores;
    int totalVotosGovernador = eleicao.totalEleitores;

    if (invalidosP > votosVencedorP || invalidosG > votosVencedorG)
    {
        printf("SEM DECISAO\n");
        return;
    }

    printf("- PRESIDENTE ELEITO: ");
    ImprimeCandidato(eleicao.presidentes[vencedorP],
        CalculaPercentualVotos(eleicao.presidentes[vencedorP], eleicao.totalEleitores));

    printf("- GOVERNADOR ELEITO: ");
    ImprimeCandidato(eleicao.governadores[vencedorG],
        CalculaPercentualVotos(eleicao.governadores[vencedorG], eleicao.totalEleitores));

    printf("- NULOS E BRANCOS: %d, %d\n", invalidosP, invalidosG);
}