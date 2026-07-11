#include <stdio.h>
#include <string.h>

#include "partida.h"

Partida partida_criar(const char *nome_j1, const char *nome_j2, int tamanho_grid)
{
    Partida p;

    strcpy(p.nomes[0], nome_j1);
    strcpy(p.nomes[1], nome_j2);

    p.grids[0] = grid_criar(tamanho_grid);
    p.grids[1] = grid_criar(tamanho_grid);

    p.turno = 0;
    p.encerrada = 0;
    p.vencedor = -1;

    return p;
}

ResultadoJogada partida_jogar(Partida *p, Posicao alvo)
{
    if (p == NULL) return JOGADA_INVALIDA;
    if (p->encerrada) return JOGADA_INVALIDA;

    int jogador = p->turno;
    int adversario = 1 - jogador;

    Grid *grindAdv = &p->grids[adversario];

    if (!posicao_valida(alvo, grindAdv->tamanho)) return JOGADA_INVALIDA;


    CelulaEstado estado = grid_celula(*grindAdv, alvo);

    if (estado == CELULA_ATINGIDA || estado == CELULA_AGUA) return JOGADA_INVALIDA;

    if (estado == CELULA_VAZIA)
    {
        grid_atirar(grindAdv, alvo);

        p->turno = adversario;

        return JOGADA_AGUA;
    }

    if (estado == CELULA_NAVIO)
    {
        int lin = posicao_linha(alvo);
        int col = posicao_coluna(alvo);

        int indNav = grindAdv->navio_idx[lin][col];

        grid_atirar(grindAdv, alvo);

        if (grid_todos_afundados(*grindAdv))
        { 
            p->encerrada = 1;
            p->vencedor = jogador;

            return JOGADA_VITORIA;
        }

        if (navio_afundado(grindAdv->navios[indNav]))
        {
            return JOGADA_AFUNDOU;
        }

        return JOGADA_ACERTO;
    }

    return JOGADA_INVALIDA;
}

int partida_encerrada(const Partida p)
{
    return p.encerrada;
}

const char *partida_vencedor(const Partida *p)
{
    if (p == NULL) return NULL;
    if (p->encerrada == 0) return NULL;

    return p->nomes[p->vencedor];
}

const char *partida_turno_atual(const Partida *p)
{
    if (p == NULL) return NULL;
    if (p->encerrada == 1) return NULL;

    return p->nomes[p->turno];
}