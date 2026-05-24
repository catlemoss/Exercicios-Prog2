/*
 * posicao.h
 * TAD Posicao — representa uma celula do grid (linha, coluna)
 *
 * INSTRUCOES: Nao modifique este arquivo. Implemente as funcoes em posicao.c
 */

#ifndef POSICAO_H
#define POSICAO_H

/* ------------------------------------------------------------------ */
/* Definicao do tipo                                                   */
/* ------------------------------------------------------------------ */

typedef struct {
    int linha;
    int coluna;
} Posicao;

/* ------------------------------------------------------------------ */
/* Operacoes                                                           */
/* ------------------------------------------------------------------ */

/*
 * posicao_criar
 * Cria e retorna uma Posicao com os valores fornecidos.
 * Pre-condicao : linha >= 0 e coluna >= 0
 * Pos-condicao : posicao retornada contem os valores fornecidos
 */
Posicao posicao_criar(int linha, int coluna);

/*
 * posicao_linha
 * Retorna a linha da posicao.
 */
int posicao_linha(Posicao p);

/*
 * posicao_coluna
 * Retorna a coluna da posicao.
 */
int posicao_coluna(Posicao p);

/*
 * posicao_igual
 * Retorna 1 se as duas posicoes sao iguais, 0 caso contrario.
 */
int posicao_igual(Posicao a, Posicao b);

/*
 * posicao_valida
 * Retorna 1 se linha e coluna estao dentro de [0, tamanho-1].
 * Pre-condicao : tamanho > 0
 */
int posicao_valida(Posicao p, int tamanho);

#endif /* POSICAO_H */
