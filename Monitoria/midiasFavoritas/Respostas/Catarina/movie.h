#ifndef MOVIE_H
#define MOVIE_H

#define MAX_TAM_STRING 50

typedef struct Movie Movie;

/**
 * @brief Lê os dados de um filme da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Diretor(a), Gênero, Ano de lançamento e Duração (em minutos).
 * @return Ponteiro para a estrutura Movie recém-criada.
 */
Movie *movie_read_and_construct();

/**
 * @brief Imprime os dados formatados de um filme.
 * A formatação exibirá, linha por linha: o Nome, o Diretor, o Ano, o Gênero e a Duração.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
void movie_print(void *m);

/**
 * @brief Libera a memória alocada para a estrutura de um filme.
 * @param m Ponteiro genérico que aponta para a estrutura Movie.
 */
void movie_free(void *m);

#endif