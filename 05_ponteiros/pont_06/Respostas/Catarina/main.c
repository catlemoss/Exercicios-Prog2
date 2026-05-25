/*
Dado o programa abaixo para apresentar todas as datas
contidas em um intervalo formado por duas datas d1 e d2.
Catarina Lemos
25/05/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "data.h"

int main()
{
    tData data;
    tData dataIni;
    tData dataFim;

    LeData(&dataIni);
    LeData(&dataFim);

    data = dataIni;

    while( !EhIgual(&data, &dataFim) )
    {
        ImprimeData(&data);
        printf("\n");
        AvancaParaDiaSeguinte(&data);
    }

    return 0;
}