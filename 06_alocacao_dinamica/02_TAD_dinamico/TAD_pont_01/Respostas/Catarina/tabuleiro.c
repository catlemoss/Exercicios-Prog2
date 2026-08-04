#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro* CriaTabuleiro()
{
    tTabuleiro *tabuleiro = malloc (sizeof(*tabuleiro));
    if (tabuleiro == NULL) exit(1);

    tabuleiro->posicoes = malloc (TAM_TABULEIRO * sizeof(*tabuleiro->posicoes));

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        tabuleiro->posicoes[i] = malloc (TAM_TABULEIRO * sizeof(*tabuleiro->posicoes[i]));

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            tabuleiro->posicoes[i][j] = '-';
        }
    }

    return tabuleiro;
}


/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 * 
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro* tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        free (tabuleiro->posicoes[i]);
    }

    free (tabuleiro->posicoes);
    free (tabuleiro);
}


/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y)
{
    if (peca == PECA_1) tabuleiro->posicoes[y][x] = 'X';
    else if (peca == PECA_2) tabuleiro->posicoes[y][x] = '0';
}


/**
 * Verifica se há alguma posição livre no tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 * 
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->posicoes[i][j] == '-') return 1;
        }
    }

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 * 
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 * 
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca)
{
    if (peca == PECA_1) return tabuleiro->posicoes[y][x] == 'X';
    if (peca == PECA_2) return tabuleiro->posicoes[y][x] == '0';

    return 0;
}


/**
 * Verifica se a posição do tabuleiro está livre.
 * 
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y)
{
    return tabuleiro->posicoes[y][x] == '-';
}


/**
 * Verifica se a posição do tabuleiro é válida.
 * 
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * 
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    return ((0 <= x && x < TAM_TABULEIRO) && (0 <= y && y < TAM_TABULEIRO));    
}


/**
 * Imprime o tabuleiro.
 * 
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro* tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        printf("\t");

        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro->posicoes[i][j]);
        }

        printf("\n");
    }
}