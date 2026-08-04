/*
Nesta atividade, você terá a oportunidade de desenvolver a implementação do Jogo da
Velha utilizando os conceitos de Tipos Abstratos de Dados (TADs)
Catarina Lemos
04/08/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "jogo.h"

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