/*
Crie um TAD do tipo Data (armazena o dia, mês e ano) que
forneça uma variedade de funções para manipulação de datas.
Catarina Lemos
13/07/2026
*/

#include "data.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    tData *data1 = CriaData();
    tData *data2 = CriaData();

    LeData(data1);
    LeData(data2);

    if (!VerificaDataValida(data1) || !VerificaDataValida(data2))
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");

        LiberaData(data1);
        LiberaData(data2);

        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    if (ComparaData(data1, data2) == 1)
    {
        printf("A primeira data eh mais antiga\n");
    }
    else if (ComparaData(data1, data2) == -1)
    {
        printf("A segunda data eh mais antiga\n");
    }
    else printf("As datas sao iguais\n");
    
    printf("A diferenca em dias entre as datas eh: %02d dias\n", 
        CalculaDiferencaDias(data1, data2));

    LiberaData(data1);
    LiberaData(data2);

    return 0;
}