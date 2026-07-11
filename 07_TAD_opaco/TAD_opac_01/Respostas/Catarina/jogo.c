#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>

struct Jogo
{
    tTabuleiro *tabuleiro;
    tJogador *j1;
    tJogador *j2;
};


/**
 * Aloca e retorna uma estrutura do tipo tJogo.
 * Se a alocação falhar, o programa é encerrado.
 * 
 * @return a estrutura do tipo tJogo alocada.
 */
tJogo* CriaJogo()
{
    tJogo *j = malloc (sizeof (tJogo));
    if (j == NULL) exit (1);

    j->tabuleiro = CriaTabuleiro();

    j->j1 = CriaJogador(ID_JOGADOR_1);
    j->j2 = CriaJogador(ID_JOGADOR_2);

    return j;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 * 
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo* jogo)
{
    int venceuJogador1 = 0;
    int venceuJogador2 = 0;

    while (1)
    {
        JogaJogador(jogo->j1, jogo->tabuleiro);
        venceuJogador1 = VenceuJogador(jogo->j1, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if (venceuJogador1 || AcabouJogo(jogo)) break;

        JogaJogador(jogo->j2, jogo->tabuleiro);
        venceuJogador2 = VenceuJogador(jogo->j2, jogo->tabuleiro);
        ImprimeTabuleiro(jogo->tabuleiro);
        if (venceuJogador2 || AcabouJogo(jogo)) break;
    }

    if (venceuJogador1) printf("JOGADOR 1 Venceu!\n");
    else if (venceuJogador2) printf("JOGADOR 2 Venceu!\n");
    else printf("Sem vencedor!\n");
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 * 
 * @param jogo o jogo atual.
 * 
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo* jogo)
{
    return (!TemPosicaoLivreTabuleiro(jogo->tabuleiro));
}


/**
 * Verifica se o usuário deseja jogar novamente.
 * 
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    printf("Jogar novamente? (s,n)\n");

    char resposta;

    while (scanf(" %c", &resposta) == 1)
    {
        if (resposta == 's') return 1;

        if (resposta == 'n') return 0;
    }

    return 0;
}


/**
 * Libera a memória de uma estrutura do tipo tJogo.
 * 
 * @param jogo a estrutura do tipo tJogo a ser liberada.
 */
void DestroiJogo(tJogo* jogo)
{
    if (jogo != NULL)
    {
        DestroiTabuleiro(jogo->tabuleiro);

        DestroiJogador(jogo->j1);
        DestroiJogador(jogo->j2);

        free (jogo);
    }
}