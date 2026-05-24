#include <stdio.h>

#include "grid.h"

Grid grid_criar(int tamanho)
{
    Grid g;

    g.tamanho = tamanho;
    g.total_navios = 0;

    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            g.celulas[i][j] = CELULA_VAZIA;
            g.parte_idx[i][j] = -1;
            g.navio_idx[i][j] = -1;
        }
    }

    return g;
}

int grid_posicionar(Grid *g, const Navio *n, Posicao inicio, int horizontal)
{
    if (g == NULL || n == NULL) return 0;

    int linhaInicial = posicao_linha(inicio);
    int colunaInicial = posicao_coluna(inicio);
    int tamanhoNav = navio_tamanho(*n);

    if (g->total_navios >= GRID_MAX_NAVIOS) return 0;

    // posicao tem nav?
    for (int i = 0; i < tamanhoNav; i++)
    {
        int linAtual = linhaInicial;
        int colAtual = colunaInicial;

        if (horizontal) colAtual = colunaInicial + i;
        else linAtual = linhaInicial + i;

        Posicao p = posicao_criar(linAtual, colAtual);

        if (!posicao_valida(p, g->tamanho)) return 0;

        if (g->celulas[linAtual][colAtual] != CELULA_VAZIA) return 0;
    }

    // pode por nav
    int indiceNav = g->total_navios;

    g->navios[indiceNav] = *n;

    for (int i = 0; i < tamanhoNav; i++)
    {
        int linAtual = linhaInicial;
        int colAtual = colunaInicial;

        if (horizontal) colAtual = colunaInicial + i;
        else linAtual = linhaInicial + i;

        g->celulas[linAtual][colAtual] = CELULA_NAVIO;
        g->navio_idx[linAtual][colAtual] = indiceNav;
        g->parte_idx[linAtual][colAtual] = i;
    }

    g->total_navios++;

    return 1;
}

int grid_atirar(Grid *g, Posicao p)
{
    if (g == NULL) return 0; 

    if (!posicao_valida(p, g->tamanho)) return 0;

    int lin = posicao_linha(p);
    int col = posicao_coluna(p);

    if (g->celulas[lin][col] == CELULA_NAVIO) 
    {
        g->celulas[lin][col] = CELULA_ATINGIDA;

        int indNav = g->navio_idx[lin][col];
        int indParte = g->parte_idx[lin][col];

        navio_atingir(&g->navios[indNav], indParte);

        return 1;
    }

    if (g->celulas[lin][col] == CELULA_VAZIA)
    {
        g->celulas[lin][col] = CELULA_AGUA;
        return 0;
    }

    return 0;
}

CelulaEstado grid_celula(const Grid g, Posicao p)
{
    int lin = posicao_linha(p);
    int col = posicao_coluna(p);

    return g.celulas[lin][col];
}

int grid_todos_afundados(const Grid g)
{
    for (int i = 0; i < g.tamanho; i++)
    {
        for (int j = 0; j < g.tamanho; j++)
        {
            if (g.celulas[i][j] == CELULA_NAVIO) return 0;
        }
    }

    return 1;
}