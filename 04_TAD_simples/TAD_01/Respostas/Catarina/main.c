/*
Um jogo da velha bem difícil.
Catarina Lemos
23/04/2026
*/

#include <stdio.h>

#include "jogo.h"

int main ()
{
    tJogo jogo = CriaJogo();

    do
    {
        ComecaJogo(jogo);

    } 
    while (ContinuaJogo());

    return 0;
}