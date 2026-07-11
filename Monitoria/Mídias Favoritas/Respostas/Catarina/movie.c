#include "movie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie
{
    char titulo[MAX_TAM_STRING];
    char diretora[MAX_TAM_STRING]; 
    char genero[MAX_TAM_STRING];
    int anoLancamento;
    int duracao;
};

// FILME Moonlight Barry_Jenkins Drama 2016 111
Movie *movie_read_and_construct()
{
    Movie *m = malloc (sizeof (Movie));

    if (m == NULL) return NULL;

    scanf("%s %s %s %d %d\n", m->titulo, m->diretora, m->genero, &m->anoLancamento, &m->duracao);

    return m;
}

void movie_print(void *m)
{
    Movie *mo = (Movie *) m;

    printf("FILME\n");

    printf("Titulo: %s\n", mo->titulo);
    printf("Diretor(a): %s\n", mo->diretora);
    printf("Genero: %s\n", mo->genero);
    printf("Ano de lancamento: %d\n", mo->anoLancamento);
    printf("Duracao: %d min\n", mo->duracao);
}

void movie_free(void *m)
{
    Movie *mo = (Movie *) m;
    free (mo);
}