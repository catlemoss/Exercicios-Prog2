#include <stdio.h>
#include <string.h>

#include "candidato.h"

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato c;
 
    strcpy(c.nome, nome);
    strcpy(c.partido, partido); 
    c.cargo = cargo;
    c.id = id;
    c.votos = 0;

    return c;
}

tCandidato LeCandidato()
{
    tCandidato c;

    scanf(" %49[^,], %49[^,], %c, %d", c.nome, c.partido, &c.cargo, &c.id);
    c.votos = 0;

    return c;
}

int VerificaIdCandidato(tCandidato candidato, int id)
{
    return candidato.id == id;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    return candidato1.id == candidato2.id;
}

char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    if (totalVotos == 0) return 0;
    return (float) candidato.votos / totalVotos * 100;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos)
{
    printf("%s (%s), %d voto(s), %.2f%%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
