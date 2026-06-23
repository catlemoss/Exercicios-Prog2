/*
Um TAD genérico que possui a capacidade de armazenar um
vetor de inteiros ou de nú meros reais, além de imprimir os dados salvos.
Catarina Lemos
22/06/2026
*/

#include "tadgen.h"

#include <stdio.h>

int main ()
{
    int tipo, nElementos;
    tGeneric *g;

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");

    scanf("%d %d", &tipo, &nElementos);

    g = CriaGenerico ((Type) tipo, nElementos);

    LeGenerico (g);
    ImprimeGenerico (g);

    DestroiGenerico (g);

    return 0;
}