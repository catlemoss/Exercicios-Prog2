/*
Um programa que simule uma urna eletrônica rudimentar que
deve ler votos dos eleitores e no final retornar o resultado da eleição e alguns dados
estatísticos.
Catarina Lemos
28/04/2026
*/

#include <stdio.h>
#include <string.h>

#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"

int main ()
{
    tEleicao eleicao;

    eleicao = InicializaEleicao();
    eleicao = RealizaEleicao(eleicao);
    ImprimeResultadoEleicao(eleicao);

    return 0;
} 