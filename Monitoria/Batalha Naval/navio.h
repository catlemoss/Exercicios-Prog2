/*
 * navio.h
 * TAD Navio — representa um navio com nome, tamanho e estado das partes
 *
 * INSTRUCOES: Nao modifique este arquivo. Implemente as funcoes em navio.c
 */

#ifndef NAVIO_H
#define NAVIO_H

#define NAVIO_MAX_TAMANHO 5
#define NAVIO_MAX_NOME    32

/* ------------------------------------------------------------------ */
/* Definicao do tipo                                                   */
/* ------------------------------------------------------------------ */

typedef struct {
    char nome[NAVIO_MAX_NOME];
    int  tamanho;
    int  partes_atingidas[NAVIO_MAX_TAMANHO]; /* 0 = intacta, 1 = atingida */
} Navio;

/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

/*
 * navio_criar
 * Preenche a estrutura com o nome e tamanho fornecidos.
 * Todas as partes comecam intactas (0).
 * Pre-condicao :  tamanho entre 1 e NAVIO_MAX_TAMANHO
 *                nome != NULL e cabe em NAVIO_MAX_NOME (com '\0')
 * Pos-condicao : todas as partes estao em 0 apos a criacao
 */
Navio navio_criar(const char *nome, int tamanho);

/*
 * navio_atingir
 * Marca a parte indicada pelo indice como atingida (1).
 * Pre-condicao : n != NULL, 0 <= parte < n->tamanho
 *                a parte ainda nao foi atingida
 */
void navio_atingir(Navio *n, int parte);

/*
 * navio_afundado
 * Retorna 1 se todas as partes foram atingidas, 0 caso contrario.

 */
int navio_afundado(const Navio n);

/*
 * navio_nome
 * Retorna um ponteiro para o nome do navio.
 * Pre-condicao : n != NULL
 */
const char *navio_nome(const Navio *n);

/*
 * navio_tamanho
 * Retorna o tamanho (numero de partes) do navio.

 */
int navio_tamanho(const Navio n);

#endif /* NAVIO_H */
