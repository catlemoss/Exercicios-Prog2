/*
Nesta atividade, você terá a oportunidade de desenvolver a implementação do Jogo da
Velha utilizando os conceitos de Tipos Abstratos de Dados (TADs) opacos, com alocação
dinâmica de memória.
Catarina Lemos
27/05/2026
*/

#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int continuar;

    do
    {
        tJogo *jogo = CriaJogo();

        ComecaJogo(jogo);
        DestroiJogo(jogo);

        continuar = ContinuaJogo();
        
    } while (continuar);

    return 0;
}