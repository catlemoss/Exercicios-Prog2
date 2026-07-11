/*
Um jogo de batalha naval.
Catarina Lemos
04/05/2026 (dia do Met)
*/

#include <stdio.h>
#include <string.h>

#include "partida.h"
#include "grid.h"
#include "navio.h"
#include "posicao.h"

int main ()
{
    char nomeJog1[PARTIDA_MAX_NOME];
    char nomeJog2[PARTIDA_MAX_NOME];
    int tamGrid;

    scanf("%s %s %d", nomeJog1, nomeJog2, &tamGrid);


    Partida partida = partida_criar(nomeJog1, nomeJog2, tamGrid);

    printf("=== BATALHA NAVAL: %s vs %s ===\n\n", nomeJog1, nomeJog2);

    // le navios dos 2 players
    for (int jogador = 0; jogador < 2; jogador++)
    {
        for (int i = 0; i < GRID_MAX_NAVIOS; i++)
        {
            int linNav, colNav, tamNav, horizontal;
            char nomeNav[NAVIO_MAX_NOME];

            scanf("%d %d %d %d %s", &linNav, &colNav, &horizontal, &tamNav,
                nomeNav);

            Navio navio = navio_criar(nomeNav, tamNav);
            Posicao inicio = posicao_criar(linNav, colNav);

            grid_posicionar(&partida.grids[jogador], &navio, inicio, horizontal);
        }
    }

    printf("Navios posicionados. Iniciando jogo...\n\n");

    int rodada = 1;
    int linJogada, colJogada, numJogador;

    while (!partida_encerrada(partida) && scanf("%d %d %d", &linJogada, &colJogada, 
        &numJogador) == 3)
    {
        if (numJogador != partida.turno)
        {
            printf("Aviso: jogador %d nao eh o turno atual (%d)\n", numJogador,
                partida.turno);
            continue;
        }

        const char *jogadorAtual = partida_turno_atual(&partida);

        Posicao alvo = posicao_criar(linJogada, colJogada);

        ResultadoJogada resultado = partida_jogar(&partida, alvo);

        printf("Rodada %d - %s atira em (%d, %d): ", rodada, jogadorAtual,
            linJogada, colJogada);

        if (resultado == JOGADA_AGUA) printf("Agua! Passa a vez.\n");
        else if (resultado == JOGADA_ACERTO) printf("Acerto!\n");
        else if (resultado == JOGADA_AFUNDOU) printf("Afundou um navio!\n");
        else if (resultado == JOGADA_VITORIA) printf("VITORIA!\n");
        else printf("Jogada invalida!\n");

        rodada++;
    }
    
    if (partida_vencedor(&partida) != NULL)
    {
        printf("\n*** PARTIDA ENCERRADA ***\n");
        printf("Vencedor: %s\n", partida_vencedor(&partida));
    }

    printf("\n");

    return 0;
}