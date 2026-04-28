#include <stdio.h>

#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

tJogo CriaJogo()
{
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();

    jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
    jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}

void ComecaJogo(tJogo jogo)
{
    jogo = CriaJogo();

    while (1)
    {
        // player 1
        jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (VenceuJogador(jogo.jogador1, jogo.tabuleiro))
        {
            printf("JOGADOR 1 Venceu!\n");
            break;
        }

        else if (AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }

        // player 2
        jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        ImprimeTabuleiro(jogo.tabuleiro);

        if (VenceuJogador(jogo.jogador2, jogo.tabuleiro))
        {
            printf("JOGADOR 2 Venceu!\n");
            break;
        }

        else if (AcabouJogo(jogo))
        {
            printf("Sem vencedor!\n");
            break;
        }
    }
}

int AcabouJogo(tJogo jogo)
{
    return !TemPosicaoLivreTabuleiro(jogo.tabuleiro);
}

int ContinuaJogo()
{
    char opcao;

    printf("Jogar novamente? (s,n)\n");
    scanf(" %c", &opcao);

    if (opcao == 's') return 1;
    else return 0;
}