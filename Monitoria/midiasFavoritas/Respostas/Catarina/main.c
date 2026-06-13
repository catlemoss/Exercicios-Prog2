/*
Nesta atividade, você construirá um sistema de gerenciamento para uma biblioteca
de entretenimento pessoal contendo Filmes, Jogos e Músicas. O desafio principal é
criar um TAD de Lista Genérica responsável por armazenar essas diferentes mídias.
10/06/2026
Catarina Lemos
*/

#include "list.h"
#include "media.h"
#include "music.h"
#include "movie.h"
#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    List *lista = list_construct();

    if (lista == NULL) return 0;

    char opcao[MAX_TAM_STRING];

    while (scanf("%49s", opcao) == 1)
    {
        if (strcmp(opcao, "IMPRIMIR") == 0)
        {
            list_print(lista);
            break;
        }

        else if (strcmp(opcao, "JOGO") == 0)
        {
            Game *jogo = game_read_and_construct();

            if (jogo != NULL)
            {
                list_media_insert(lista, jogo, game_print, game_free);
            }
        }

        else if (strcmp(opcao, "FILME") == 0)
        {
            Movie *filme = movie_read_and_construct();

            if (filme != NULL)
            {
                list_media_insert(lista, filme, movie_print, movie_free);
            }
        }

        else if (strcmp(opcao, "MUSICA") == 0)
        {
            Music *musica = music_read_and_construct();

            if (musica != NULL)
            {
                list_media_insert(lista, musica, music_print, music_free);
            }
        }
    }

    list_free(lista);

    return 0;
}