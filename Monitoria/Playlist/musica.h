#ifndef _MUSICA_H_
#define _MUSICA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAM_STRING 30

typedef struct
{
    char *nome;
    char *artista;
    char *album;
    char *genero;
} Musica;

typedef void (*tipoImpressaoMusica)(Musica *);
typedef int (*compara)(Musica *, char *);

/**
 * @brief cria um dado do tipo musica, ponteiros devem receber NULL e atributos numericos 0
 * @return retorna a musica criada
 */
Musica *criaMusica();

/**
 * @brief le os atributos de uma musica
 * @param music ponteiro para a musica
 */
void leMusica(Musica *music);

/**
 * @brief compara duas musicas
 * @param music_1 primeira musica
 * @param music_2 segunda musica
 * @return 1 se forem iguais e qualquer outro valor caso contrario
 */
int comparaMusicas(Musica *music_1, Musica *music_2);

/**
 * @brief compara o nome de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaNomeMus(Musica *music, char *name);

/**
 * @brief compara o artista de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaArtistaMus(Musica *music, char *artist);

/**
 * @brief compara o album de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaAlbumMus(Musica *music, char *album);

/**
 * @brief compara o genero de uma musica com a string fornecida
 * @return 1 se forem iguais, 0 caso contrario
 */
int comparaGeneroMus(Musica *music, char *genre);

/**
 * @brief imprime uma musica no formato [nome] - [artista] ............ [album]
 * @param music musica a ser impressa
 */
void imprimeMusica(Musica *music);

/**
 * @brief imprime uma musica no formato [nome]
 * @param musica a ser impressa
 */
void imprimeMusica_Album(Musica *music);

/**
 * @brief imprime uma musica no formato [nome] - [album]
 * @param musica a ser impressa
 */
void imprimeMusica_Artista(Musica *music);

/**
 * @brief imprime uma musica no formato [nome] - [artista]
 * @param music musica a ser impressa
 */
void imprimeMusica_Genero(Musica *music);

/**
 * @brief desaloca uma musica da memoria
 * @param music musica a ser desalocada
 */
void apagaMusica(Musica *music);

#endif