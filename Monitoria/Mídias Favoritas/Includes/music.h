#ifndef MUSIC_H
#define MUSIC_H

#define MAX_TAM_STRING 50

typedef struct Music Music;

/**
 * @brief Lê os dados de uma música da entrada padrão e constrói a estrutura correspondente.
 * A ordem de leitura esperada é: Título, Artista, Quantidade de Feats, Lista com os nomes dos Feats, Álbum e Gênero.
 * @return Ponteiro para a estrutura Music recém-criada.
 */
Music *music_read_and_construct();

/**
 * @brief Imprime os dados formatados de uma música.
 * A formatação exibirá, linha por linha: o Nome, o Artista, os Feats (se a quantidade for maior que zero), o Álbum e o Gênero.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
void music_print(void *m);

/**
 * @brief Libera a memória alocada para a estrutura de uma música.
 * @param m Ponteiro genérico que aponta para a estrutura Music.
 */
void music_free(void *m);

#endif