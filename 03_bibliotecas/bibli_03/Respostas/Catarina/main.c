/*
Um programa com uma biblioteca que forneça uma variedade de funções para
manipulação de datas.
Catarina Lemos
19/04/2026
*/

#include <stdio.h>

#include "data.h"

int main ()
{
    int dia1, mes1, ano1;
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);

    int dia2, mes2, ano2;
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if (verificaDataValida(dia1, mes1, ano1) == 0 ||
        verificaDataValida(dia2, mes2, ano2) == 0)
    {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 0;
    }

    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);

    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);

    int compara = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);

    if (compara == -1)
    {
        printf("A primeira data eh mais antiga\n");

    } else if (compara == 1)
    {
        printf("A segunda data eh mais antiga\n");

    } else printf("As datas sao iguais\n");

    printf("A diferenca em dias entre as datas eh: ");

    int numDias = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);

    if (numDias < 10) printf("%02d dias\n", numDias);
    else printf("%d dias\n", numDias);

    return 0;
}