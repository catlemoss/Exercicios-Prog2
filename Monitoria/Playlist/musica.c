#include "musica.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

#define MAX_TAM_STRING 30

typedef struct
{
    char *nome;
    char *artista;
    char *album;
    char *genero;
} Musica;

typedef void (*tipoImpressaoMusica)(Musica *);
// ponteiro para uma função que recebe Musica * e retorna void

typedef int (*compara)(Musica *, char *);
// ponteiro para uma função que recebe Musica * e char *, e retorna int

*/

Musica *criaMusica()
{
    Musica *m = malloc( sizeof( Musica));

    if (m == NULL) return NULL;

    m->nome = NULL;
    m->artista = NULL;
    m->album = NULL;
    m->genero = NULL;

    return m;
}

void leMusica(Musica *music)
{
    music->nome = malloc(MAX_TAM_STRING * sizeof(char));
    music->artista = malloc(MAX_TAM_STRING * sizeof(char));
    music->album = malloc(MAX_TAM_STRING * sizeof(char));
    music->genero = malloc(MAX_TAM_STRING * sizeof(char));

    if (music->nome == NULL || music->artista == NULL || music->album == NULL || music->genero == NULL)
    {
        return;
    }

    scanf(" %29[^\n]\n", music->nome);
    scanf(" %29[^\n]\n", music->artista);
    scanf(" %29[^\n]\n", music->album);
    scanf(" %29[^\n]\n", music->genero);
}

int comparaMusicas(Musica *music_1, Musica *music_2)
{
    if (strcmp(music_1->nome, music_2->nome) == 0 &&
        strcmp(music_1->artista, music_2->artista) == 0 &&
        strcmp(music_1->album, music_2->album) == 0 &&
        strcmp(music_1->genero, music_2->genero) == 0)
    {
        return 1;
    }

    return 0;
    // strcmp da 0 quando sao iguais. achei estranho
}

int comparaNomeMus(Musica *music, char *name)
{
    return strcmp(music->nome, name) == 0;
}

int comparaArtistaMus(Musica *music, char *artist)
{
    return strcmp(music->artista, artist) == 0;
}

int comparaAlbumMus(Musica *music, char *album)
{
    return strcmp(music->album, album) == 0;
}

int comparaGeneroMus(Musica *music, char *genre)
{
    return strcmp(music->genero, genre) == 0;
}

void imprimeMusica(Musica *music)
{
    printf("%s - %s ............ %s\n", music->nome, music->artista, music->album);
}

void imprimeMusica_Album(Musica *music)
{
    printf("%s\n", music->nome);
}

void imprimeMusica_Artista(Musica *music)
{
    printf("%s - %s\n", music->nome, music->album);
}

void imprimeMusica_Genero(Musica *music)
{
    printf("%s - %s\n", music->nome, music->artista);
}

void apagaMusica(Musica *music)
{
    if (music == NULL) return;

    free(music->nome);
    free(music->artista);
    free(music->album);
    free(music->genero);
    // tem q liberar cada coisinha antes de apagar tudo

    free(music);
}