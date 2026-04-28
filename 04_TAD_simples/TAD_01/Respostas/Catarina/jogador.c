#include <stdio.h>

#include "jogador.h"
#include "tabuleiro.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador)
{
    tJogador j;
    
    j.id = idJogador;

    return j;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    tJogada jogada;
    int x = 0, y = 0;

    while (1)
    {
        printf("Jogador %d\n", jogador.id);

        jogada = LeJogada();

        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);

        if (EhPosicaoValidaTabuleiro(x, y))
        {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
            {
                printf("Jogada [%d,%d]!\n", x, y);

                tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, x, y);
                break;
            }

            else 
            {
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            }
        }

        else 
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
    }

    return tabuleiro;
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    int venceu = 1;

    char peca;
    if (jogador.id == ID_JOGADOR_1) peca = tabuleiro.peca1;
    else peca = tabuleiro.peca2;

    // linhas e colunas
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        venceu = 1;

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            venceu = venceu && tabuleiro.posicoes[j][i] == peca;
        }

        if (venceu) return 1;
    }

    // diagonais
    if ((tabuleiro.posicoes[0][0] == peca & tabuleiro.posicoes[1][1] == peca 
        && tabuleiro.posicoes[2][2] == peca) 
        || 
        (tabuleiro.posicoes[0][2] == peca && tabuleiro.posicoes[1][1] == peca && tabuleiro.posicoes[2][0] == peca))
    {
        return 1;
    }

    return 0;
}