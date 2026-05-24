#include <stdio.h>
#include <string.h>

#include "navio.h"

Navio navio_criar(const char *nome, int tamanho)
{
    Navio n;

    n.tamanho = tamanho;
    strcpy(n.nome, nome);

    for (int i = 0; i < tamanho; i++)
    {
        n.partes_atingidas[i] = 0;
    }

    return n;
}

void navio_atingir(Navio *n, int parte)
{
    if (n == NULL) return;

    n->partes_atingidas[parte] = 1;
}

int navio_afundado(const Navio n)
{
    for (int i = 0; i < n.tamanho; i++)
    {
        if (n.partes_atingidas[i] == 0) return 0; // navio intacto
    }

    return 1;
}

const char *navio_nome(const Navio *n)
{
    if (n == NULL) return NULL;

    return n->nome;
}

int navio_tamanho(const Navio n)
{
    return n.tamanho;
}