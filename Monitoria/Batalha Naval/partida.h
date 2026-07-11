/*
 * partida.h
 * TAD Partida — orquestra o jogo entre dois jogadores
 *
 * INSTRUCOES: Nao modifique este arquivo. Implemente as funcoes em partida.c
 */

#ifndef PARTIDA_H
#define PARTIDA_H

#include "grid.h"
#include "posicao.h"

#define PARTIDA_MAX_NOME 64

/* ------------------------------------------------------------------ */
/* Resultado possivel de uma jogada                                    */
/* ------------------------------------------------------------------ */

typedef enum {
    JOGADA_AGUA     = 0,  /* tiro na agua                        */
    JOGADA_ACERTO   = 1,  /* acertou uma parte de navio          */
    JOGADA_AFUNDOU  = 2,  /* acertou e afundou um navio inteiro  */
    JOGADA_VITORIA  = 3,  /* acertou e venceu a partida          */
    JOGADA_INVALIDA = 4   /* posicao invalida ou ja atirada      */
} ResultadoJogada;

/* ------------------------------------------------------------------ */
/* Definicao do tipo                                                   */
/* ------------------------------------------------------------------ */

typedef struct {
    char nomes[2][PARTIDA_MAX_NOME]; /* nomes[0] = jogador 1, nomes[1] = jogador 2 */
    Grid grids[2];                   /* grids[0] = grid do jogador 1, etc.          */
    int  turno;                      /* 0 ou 1 — indice do jogador atual            */
    int  encerrada;                  /* 1 se a partida terminou                     */
    int  vencedor;                   /* indice do vencedor (-1 se ainda em curso)   */
} Partida;

/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

/*
 * partida_criar
 * Inicializa a partida com dois jogadores e grids do tamanho indicado.
 * O turno inicial e do jogador 1 (indice 0).
 * Pre-condicao : p != NULL, nome_j1 != NULL, nome_j2 != NULL
 *                2 <= tamanho_grid <= GRID_MAX_TAMANHO
 */
Partida partida_criar(const char *nome_j1, const char *nome_j2,
                   int tamanho_grid);

/*
 * partida_jogar
 * O jogador do turno atual atira na posicao `alvo` no grid adversario.
 * Avanca o turno somente se a jogada for valida.
 * Pre-condicao : p != NULL, p->encerrada == 0
 * Pos-condicao : se resultado == JOGADA_VITORIA, p->encerrada = 1
 */
ResultadoJogada partida_jogar(Partida *p, Posicao alvo);

/*
 * partida_encerrada
 * Retorna 1 se a partida terminou, 0 caso contrario.
 * Pre-condicao : p != NULL
 */
int partida_encerrada(const Partida p);

/*
 * partida_vencedor
 * Retorna o nome do vencedor, ou NULL se a partida ainda nao terminou.
 * Pre-condicao : p != NULL
 */
const char *partida_vencedor(const Partida *p);

/*
 * partida_turno_atual
 * Retorna o nome do jogador que deve jogar agora.
 * Pre-condicao : p != NULL, p->encerrada == 0
 */
const char *partida_turno_atual(const Partida *p);

#endif /* PARTIDA_H */
