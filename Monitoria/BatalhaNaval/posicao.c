#include <stdio.h>

#include "posicao.h"

Posicao posicao_criar(int linha, int coluna)
{
    Posicao p;

    if (linha >= 0) p.linha = linha;
    else p.linha = 0;

    if (coluna >= 0) p.coluna = coluna;
    else p.coluna = 0; 

    return p;
}

int posicao_linha(Posicao p)
{
    return p.linha;
}

int posicao_coluna(Posicao p)
{
    return p.coluna;
}

int posicao_igual(Posicao a, Posicao b)
{
    return (a.linha == b.linha && a.coluna == b.coluna);
}

int posicao_valida(Posicao p, int tamanho)
{
    if (tamanho <= 0) return 0;

    return (0 <= p.linha && p.linha < tamanho && 0 <= p.coluna && p.coluna < tamanho);
}