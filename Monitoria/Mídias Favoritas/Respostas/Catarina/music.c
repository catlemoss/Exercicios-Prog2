#include "music.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Music
{
    char titulo[MAX_TAM_STRING];
    char artista[MAX_TAM_STRING];
    int nFeats;
    char participantes[MAX_TAM_STRING][MAX_TAM_STRING];     // vetor de string aka matriz de char
    // o primeiro quadrado é o nfeats e o segundo guarda a palavra
    char album[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
};

// MUSICA EARFQUAKE Tyler_The_Creator 1 Playboi_Carti IGOR Hip-Hop
Music *music_read_and_construct()
{
    Music *m = malloc (sizeof (Music));

    if (m == NULL) return NULL;

    scanf("%s %s %d", m->titulo, m->artista, &m->nFeats);

    for (int i = 0; i < m->nFeats; i++)
    {
        scanf("%s ", m->participantes[i]);
    }
    
    scanf("%s %s\n", m->album, m->genero);

    return m;

}

void music_print(void *m)
{
    Music *mu = (Music *) m;

    printf("MUSICA\n");

    printf("Titulo: %s\n", mu->titulo);
    printf("Artista: %s", mu->artista);

    if (mu->nFeats > 0)
    {
        printf(" feat. ");

        for (int i = 0; i < mu->nFeats; i++)
        {
            printf("%s", mu->participantes[i]);

            if (i < mu->nFeats - 1) printf(", ");
        }
    }

    printf("\n");

    printf("Album: %s\n", mu->album);
    printf("Genero: %s\n", mu->genero);
}

void music_free(void *m)
{
    Music *mu = (Music *) m;
    free (mu);
}