#ifndef GAME_H
#define GAME_H

#define MAX_TAM_STRING 50

typedef struct Game Game;

/**
 * @brief Lê os dados de um jogo da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Desenvolvedora, Gênero, Ano de lançamento, Quantidade de plataformas e a lista com o nome de cada plataforma.
 * @return Ponteiro para a estrutura Game recém-criada.
 */
Game *game_read_and_construct();

/**
 * @brief Imprime os dados formatados de um jogo.
 * A formatação exibirá, linha por linha: o Nome, a Desenvolvedora, o Ano, o Gênero e a lista de Plataformas disponíveis.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */
void game_print(void *g);

/**
 * @brief Libera a memória alocada para a estrutura de um jogo.
 * @param g Ponteiro genérico que aponta para a estrutura Game.
 */
void game_free(void *g);

#endif