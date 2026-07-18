/*
Foi solicitado a você fazer outro relatório sobre os produtos vendidos
pelos estabelecimentos do exercício anterior. Dessa vez, o relatório deverá informar
o valor total vendido.
Catarian Lemos
05/07/2026
*/

#include "estabelecimento.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    tEstabelecimento *e = CriaEstabelecimento();

    LeEstabelecimento(e);

    ImprimeRelatorioEstabelecimento(e);

    DestroiEstabelecimento(e);

    return 0;
}