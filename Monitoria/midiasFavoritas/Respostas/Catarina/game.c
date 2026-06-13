#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Game
{
    char titulo[MAX_TAM_STRING];
    char desenvolvedora[MAX_TAM_STRING];
    char genero[MAX_TAM_STRING];
    int anoLançamento;
    int nPlataformas;
    char plataformas[MAX_TAM_STRING][MAX_TAM_STRING];
};

// JOGO Hollow_Knight Team_Cherry Metroidvania 2017 4 PC Switch PS4 Xbox_One
Game *game_read_and_construct()
{
    Game *g = malloc (sizeof (Game));

    if (g == NULL) return NULL;

    scanf("%s %s %s %d %d ", g->titulo, g->desenvolvedora, g->genero, &g->anoLançamento, 
        &g->nPlataformas);

    for (int i = 0; i < g->nPlataformas; i++)
    {
        scanf("%s ", g->plataformas[i]);
    }

    return g;
}

void game_print(void *g)
{
    Game *game = (Game *) g;

    printf("JOGO\n");

    printf("Titulo: %s\n", game->titulo);
    printf("Desenvolvedora: %s\n", game->desenvolvedora);
    printf("Genero: %s\n", game->genero);
    printf("Ano de lancamento: %d\n", game->anoLançamento);

    printf("Plataforma(s): ");

    for (int i = 0; i < game->nPlataformas; i++)
    {
        printf("%s", game->plataformas[i]);

        if (i < game->nPlataformas - 1) printf(", ");
    }
    printf("\n");
}

void game_free(void *g)
{
    Game *game = (Game *) g;
    free (game);
}