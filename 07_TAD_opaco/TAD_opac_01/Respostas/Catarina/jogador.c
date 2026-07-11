#include "jogador.h"

#include "jogada.h"

#include <stdio.h>
#include <stdlib.h>

struct Jogador
{
    int id;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogador.
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 * 
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador* CriaJogador(int idJogador)
{
    tJogador *j = malloc (sizeof (tJogador));
    if (j == NULL) exit (1);

    j->id = idJogador;

    return j;
}


/**
 * Libera a memória de uma estrutura do tipo tJogador.
 * 
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador* jogador)
{
    free (jogador);
}


/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    tJogada *jogada = CriaJogada();

    while (1)
    {
        printf("Jogador %d\n", jogador->id);

        LeJogada(jogada);

        if (!FoiJogadaBemSucedida(jogada))
        {
            printf("Formato invalido!\n");
            continue;
        }

        int x = ObtemJogadaX(jogada);
        int y = ObtemJogadaY(jogada);

        if (!EhPosicaoValidaTabuleiro(x, y))
        {
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
            continue;
        }

        if (!EstaLivrePosicaoTabuleiro(tabuleiro, x, y))
        {
            printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            continue;
        }

        MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);

        printf("Jogada [%d,%d]!\n", x, y);

        break;
    }

    DestroiJogada(jogada);
}


/**
 * Verifica se o jogador venceu o jogo.
 * 
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro)
{
    int peca = jogador->id;

    // linhas
    for (int i = 0; i < 3; i++)
    {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 0, peca) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 1, peca) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, 2, peca))
        {
            return 1;
        }
    }

    // coluna
    for (int j = 0; j < 3; j++)
    {
        if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, j, peca) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, j, peca) &&
            EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, j, peca))
        {
            return 1;
        }
    }

    // diag 1
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, peca))
    {
        return 1;
    }

    // diag 2
    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, peca) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, peca))
    {
        return 1;
    }

    return 0;
}