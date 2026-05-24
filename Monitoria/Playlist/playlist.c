#include "playlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
#define TAM_MAX_MUSICAS 50

typedef struct
{
    char *nome;                     // nome da playlost
    Musica **musicas;               // vetor de msicas
    int qtdMusicas;
} Playlist;

*/

Playlist *criaPlaylist(char *name)
{
    if (name == NULL) return NULL;
    // proteção?

    Playlist *p = malloc( sizeof( Playlist));
    // espaço para a playlist

    if (p == NULL) return NULL;

    p->qtdMusicas = 0;
    // nao temos musicas ainda

    p->nome = malloc( (strlen(name) + 1) * sizeof( char));
    // espaço para o nome

    if (p->nome == NULL)
    {
        free(p);
        return NULL;
    }

    strcpy(p->nome, name);
    // pega nome da playlist

    p->musicas = malloc( TAM_MAX_MUSICAS * sizeof( Musica *));
    // vetor de musicas

    if (p->musicas == NULL)
    {
        free(p->nome);
        free(p);
        return NULL;
    }

    for (int i = 0; i < TAM_MAX_MUSICAS; i++)
    {
        p->musicas[i] = NULL;
        // inicializa a playlist
    }

    return p;
}

void adicionaMusica(Playlist *playlist)
{
    if (playlist == NULL) return;

    if (playlist->qtdMusicas >= TAM_MAX_MUSICAS)
    {
        char lixo[MAX_TAM_STRING];

        scanf(" %29[^\n]\n", lixo);   // nome
        scanf(" %29[^\n]\n", lixo);   // artista
        scanf(" %29[^\n]\n", lixo);   // album
        scanf(" %29[^\n]\n", lixo);   // genero

        // para consumir as linhas de entrada e nao zoar a leitura
        
        printf("PLAYLIST CHEIA!\n");
        return;
    }

    Musica *musica = criaMusica();

    if (musica == NULL) return;

    leMusica(musica);

    for (int i = 0; i < playlist->qtdMusicas; i++)
    {
        if (playlist->musicas[i] != NULL &&
            comparaMusicas(playlist->musicas[i], musica) == 1)
        {
            printf("A MUSICA JA ESTA NA PLAYLIST!\n");
            apagaMusica(musica);

            return;
        }
    }

    playlist->musicas[playlist->qtdMusicas] = musica;
    playlist->qtdMusicas++;
}

int removeMusica(Playlist *playlist, char *music, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist == NULL || music == NULL || comparador == NULL || impMus == NULL)
    {
        return 0;
    }

    for (int i = 0; i < playlist->qtdMusicas; i++)
    {
        if (playlist->musicas[i] != NULL && comparador(playlist->musicas[i], music) == 1) {
            printf("MUSICA REMOVIDA: ");
            impMus(playlist->musicas[i]);

            apagaMusica(playlist->musicas[i]);

            for (int j = i; j < playlist->qtdMusicas - 1; j++)
            {
                playlist->musicas[j] = playlist->musicas[j + 1];
            }

            playlist->musicas[playlist->qtdMusicas - 1] = NULL;
            playlist->qtdMusicas--;

            // para ajeitar a funçaõ depois de remover musica

            return 1;
        }
    }

    printf("A MUSICA NAO ESTA NA PLAYLIST\n");
    return 0;
}

// key = chave de busca (por exemplo: nome do artista)
void impressFunction(Playlist *playlist, char *key, compara comparador, tipoImpressaoMusica impMus)
{
    if (playlist == NULL || impMus == NULL) return;

    printf("---------------------------------------\n");

    if (comparador == NULL) printf("%s\n\n", playlist->nome);
    else printf("%s\n\n", key);
    
    for (int i = 0; i < playlist->qtdMusicas; i++)
    {
        if (playlist->musicas[i] != NULL)
        {
            if (comparador == NULL)
            {
                impMus(playlist->musicas[i]);
            }

            else if (key != NULL && comparador(playlist->musicas[i], key) == 1)
            {
                impMus(playlist->musicas[i]);
            }
        }
    }

    printf("---------------------------------------\n");
}

void apagaPlaylist(Playlist *playlist)
{
    if (playlist == NULL) return;

    if (playlist->musicas != NULL)
    {
        for (int i = 0; i < playlist->qtdMusicas; i++)
        {
            if (playlist->musicas[i] != NULL)
            {
                apagaMusica(playlist->musicas[i]);
                // primeiro apaga as musicas
            }
        }

        free(playlist->musicas);
    }

    free(playlist->nome);
    // dps o nome

    free(playlist);
    // dps a playlist
}