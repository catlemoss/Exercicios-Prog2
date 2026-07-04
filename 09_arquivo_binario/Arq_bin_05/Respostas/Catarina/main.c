/*
Para este exercício, é necessário ler os dados dos produtos vendidos
por um estabelecimento a partir de um arquivo binário.
Catarina Lemos
04/07/2026
*/

#include "estabelecimento.h"

#include <stdio.h>

int main ()
{
    tEstabelecimento *e = CriaEstabelecimento();

    LeEstabelecimento(e);

    ImprimeProdutosEmFaltaEstabelecimento(e);
    
    DestroiEstabelecimento(e);

    return 0;
}