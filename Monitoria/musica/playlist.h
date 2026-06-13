#ifndef _PLAYLIST_H_
#define _PLAYLIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musica.h"

#define TAM_MAX_MUSICAS 50

typedef struct
{
    char *nome;
    Musica **musicas;
    int qtdMusicas;
} Playlist;

/**
 * @brief cria uma playlist vazia com todas as posicoes do array de musicas como NULL
 */
Playlist *criaPlaylist(char *name);

/**
 * @brief adiciona uma musica em uma playlist
 * @param playlist playlist onde a musica sera adiconada
 */
void adicionaMusica(Playlist *playlist);

/**
 * @brief remove uma musica de uma playlist
 * @param playlist playlist a ter a musica removida
 * @param music nome da musica a ser removida
 * @param impMus ponteiro para funcao de impressao de musica
 * @return 1 caso a musica seja removida com sucesso e 0 caso o contrario
 */
int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus);

/**
 * @brief Função genérica que realiza impressões filtradas na playlist (todas as impressoes sao feitas por essa funcao)
 * @param playlist playlist a ser percorrida
 * @param key chave de busca (por exemplo: nome do artista)
 * @param modo função que implementa o modo de impressão/filtragem
 *             (ex.: `imprimePorArtista`).
 * @param impMus ponteiro para funcao de impressao de musica.
 *
 * Dica: ponteiros para função também podem ser NULL
 */
void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus);

/**
 * @brief desaloca uma playlist da memoria
 * @param playlist playlist a ser deslocada
 */
void apagaPlaylist(Playlist *playlist);

#endif