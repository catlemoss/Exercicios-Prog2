/*
Uma playlist para uma festa.
Catarina Lemos
16/05/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "playlist.h"
#include "musica.h"

int main ()
{
    char nomePlaylist[MAX_TAM_STRING];
    int qntAcoes;
    int comando;
    char chave[MAX_TAM_STRING];             // chave de busca

    // le nome playlist
    scanf(" %29[^\n]\n", nomePlaylist);

    // numero de acoes
    scanf("%d\n", &qntAcoes);

    Playlist *playlist = criaPlaylist(nomePlaylist);
    if (playlist == NULL) return 1;

    for (int i = 0; i < qntAcoes; i++)
    {
        scanf("%d", &comando);

        switch (comando)                    // usar switch aqui ficou mais bonito
        {
            case 1:
            // 1 - Inserir música
                adicionaMusica(playlist);
                break;

            case 2:
            // 2 - Remover música
                scanf(" %29[^\n]", chave);
                removeMusica(playlist, chave, comparaNomeMus, imprimeMusica_Album);
                break;

            case 3:
            // 3 - Imprimir playlist
                impressFunction(playlist, NULL, NULL, imprimeMusica);
                break;

            case 4:
            // 4 - Imprimir músicas de um artista
                scanf(" %29[^\n]", chave);
                impressFunction(playlist, chave, comparaArtistaMus, imprimeMusica_Artista);
                break;

            case 5:
            // 5 - Imprimir músicas de um álbum
                scanf(" %29[^\n]", chave);
                impressFunction(playlist, chave, comparaAlbumMus, imprimeMusica_Album);
                break;

            case 6:
            // 6 - Imprimir músicas de um gênero
                scanf(" %29[^\n]", chave);
                impressFunction(playlist, chave, comparaGeneroMus, imprimeMusica_Genero);
                break;
        }
    }

    apagaPlaylist(playlist);

    return 0;
}