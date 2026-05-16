/*
 * grid.h
 * TAD Grid — tabuleiro N×N com navios posicionados
 *
 * INSTRUCOES: Nao modifique este arquivo. Implemente as funcoes em grid.c
 */

#ifndef GRID_H
#define GRID_H

#include "posicao.h"
#include "navio.h"

#define GRID_MAX_TAMANHO  10
#define GRID_MAX_NAVIOS    5

/* ------------------------------------------------------------------ */
/* Estados possiveis de uma celula                                     */
/* ------------------------------------------------------------------ */

typedef enum {
    CELULA_VAZIA    = 0,  /* sem navio, nao atirada      */
    CELULA_NAVIO    = 1,  /* possui navio, nao atirada   */
    CELULA_ATINGIDA = 2,  /* havia navio, foi atingida   */
    CELULA_AGUA     = 3   /* sem navio, foi atirada      */
} CelulaEstado;

/* ------------------------------------------------------------------ */
/* Definicao do tipo                                                   */
/* ------------------------------------------------------------------ */

typedef struct {
    int          tamanho;
    CelulaEstado celulas[GRID_MAX_TAMANHO][GRID_MAX_TAMANHO];
    Navio        navios[GRID_MAX_NAVIOS];
    int          parte_idx[GRID_MAX_TAMANHO][GRID_MAX_TAMANHO]; /* matriz contendo o indice da parte do navio em cada celula (-1 se sem navio) */
    int          navio_idx[GRID_MAX_TAMANHO][GRID_MAX_TAMANHO]; /* matriz contendo o indice do navio em cada celula (-1 se sem navio)          */
    int          total_navios;
} Grid;

/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

/*
 * grid_criar
 * Inicializa o grid com todas as celulas vazias e sem navios.
 * Pre-condicao : 2 <= tamanho <= GRID_MAX_TAMANHO
 */
Grid grid_criar(int tamanho);

/*
 * grid_posicionar
 * Posiciona o navio apontado por n a partir de `inicio`.
 * Se horizontal == 1, ocupa colunas consecutivas; caso contrario, linhas.
 * Retorna 1 se posicionado com sucesso, 0 se posicao invalida ou sobreposicao.
 * Pre-condicao : g != NULL, n != NULL
 *                total_navios < GRID_MAX_NAVIOS antes da chamada
 * Pos-condicao : celulas ocupadas ficam com estado CELULA_NAVIO
 */
int grid_posicionar(Grid *g, const Navio *n, Posicao inicio, int horizontal);

/*
 * grid_atirar
 * Atira na posicao p.
 * Retorna 1 se acertou um navio, 0 se agua.
 * Pre-condicao : g != NULL
 *                posicao_valida(p, g->tamanho) == 1
 *                celula em p nao esta em CELULA_ATINGIDA nem CELULA_AGUA
 * Pos-condicao : celula em p muda para CELULA_ATINGIDA ou CELULA_AGUA
 *                se acertou, a parte correspondente do navio e marcada
 */
int grid_atirar(Grid *g, Posicao p);

/*
 * grid_celula
 * Retorna o estado da celula na posicao p.
 * Pre-condicao : g != NULL, posicao_valida(p, g->tamanho) == 1
 */
CelulaEstado grid_celula(const Grid g, Posicao p);

/*
 * grid_todos_afundados
 * Retorna 1 se nao ha mais nenhuma celula com estado CELULA_NAVIO.
 * Pre-condicao : g != NULL
 */
int grid_todos_afundados(const Grid g);

#endif /* GRID_H */
