/*
Crie um TAD do tipo Data que forneça uma variedade de funções
para manipulação de datas.
Catarina Lemos
21/05/2026
*/

#include "data.h"

#include <stdio.h>

int main ()
{
    int dia1, mes1, ano1;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);

    int dia2, mes2, ano2;
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    tData data1 = CriaData(dia1, mes1, ano1);
    tData data2 = CriaData(dia2, mes2, ano2);

    if (VerificaDataValida(data1) == 0 || VerificaDataValida(data2) == 0)
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    int compara = ComparaData(data1, data2);

    if (compara == -1)
    {
        printf("A primeira data eh mais antiga\n");

    } else if (compara == 1)
    {
        printf("A segunda data eh mais antiga\n");

    } else printf("As datas sao iguais\n");

    printf("A diferenca em dias entre as datas eh: ");

    int numDias = CalculaDiferencaDias(data1, data2);

    if (numDias < 10) printf("%02d dias\n", numDias);
    else printf("%d dias\n", numDias);

    return 0;
}