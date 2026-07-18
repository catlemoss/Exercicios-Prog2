/*
Este exercício consiste em implementar funções para salvar um vetor que
contém elementos de qualquer tipo (vetor genérico) em um arquivo binário.
Catarina Lemos
18/07/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "database.h"

int main()
{
    tDatabase *base = CriaDatabase();

    LeDatabase(base);
    OrdenaDatabase(base);

    char nomeArq[100];
    scanf(" %99s", nomeArq);

    FILE *arq = fopen(nomeArq, "wb");
    if (arq == NULL)
    {
        DestroiDatabase(base);
        return 1;
    }

    int bytesSalvos = SalvarDatabase(base, arq);
    fclose(arq);

    printf("Numero de bytes salvos: %d\n", bytesSalvos);

    DestroiDatabase(base);
    base = CriaDatabase();

    arq = fopen(nomeArq, "rb");
    if (arq == NULL)
    {
        DestroiDatabase(base);
        return 1;
    }

    int bytesLidos = CarregaDatabase(base, arq);
    fclose(arq);
    
    printf("Numero de bytes lidos: %d\n\n", bytesLidos);

    ImprimeDatabase(base);
    DestroiDatabase(base);

    return 0;
}