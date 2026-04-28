#include <stdio.h>

#include "tabuleiro.h"

tTabuleiro CriaTabuleiro()
{
    tTabuleiro t = {0};

    t.peca1 = 'X';
    t.peca2 = '0';
    t.pecaVazio = '-';

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            t.posicoes[i][j] = t.pecaVazio;
        }
    }

    return t;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y)
{
    if (peca == 1)
    {
        tabuleiro.posicoes[y][x] = tabuleiro.peca1;
    }
    else if (peca == 2)
    {
        tabuleiro.posicoes[y][x] = tabuleiro.peca2;
    }

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro.posicoes[j][i] == tabuleiro.pecaVazio) return 1;
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca)
{
    if (peca == 1) return tabuleiro.posicoes[y][x] == tabuleiro.peca1;
    else return tabuleiro.posicoes[y][x] == tabuleiro.peca2;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y)
{
    if (tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio) return 1;
    else return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y)
{
    if ((-1 < x && x < TAM_TABULEIRO) && (-1 < y && y < TAM_TABULEIRO)) return 1;
    else return 0;
}

void ImprimeTabuleiro(tTabuleiro tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("        ");
    
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro.posicoes[i][j] != tabuleiro.pecaVazio;

            printf("%c", tabuleiro.posicoes[i][j]);
        }

        printf("\n");
    }
}