#include <stdio.h>

#include "jogada.h"

tJogada LeJogada()
{
    tJogada j;
    int x, y;

    printf("Digite uma posicao (x e y): \n");

    if (scanf("%d %d", &x, &y) == 2)
    {
        j.x = x;
        j.y = y;
        j.sucesso = 1;
    }
    else 
    {
        j.x = x;
		j.y = y;
		j.sucesso = 0;
    }

    return j;
}

int ObtemJogadaX(tJogada jogada)
{
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada)
{
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada)
{
    return jogada.sucesso;
}