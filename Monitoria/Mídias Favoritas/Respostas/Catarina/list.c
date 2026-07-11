#include "list.h"
#include "media.h"

#include <stdio.h>
#include <stdlib.h>

struct List
{
    Media **midias;                 // vet de ponteiros para Media
    int qntMidias;
    int maxMidias;
};

// Ponteiro para a estrutura List instanciada.
List *list_construct()
{
    List *l = malloc (sizeof (List));

    if (l == NULL) return NULL;

    l->qntMidias = 0;
    l->maxMidias = MAX_TAM_MIDIAS;

    l->midias = malloc (l->maxMidias * sizeof (Media *));

    return l;
}

// Insere um novo item genérico na lista.
void list_media_insert(List *r, void *data, PrintFunction print_fn, FreeFunction free_fn)
{
    if (r == NULL) return;

    if (r->qntMidias == r->maxMidias)
    {
        int newMax = r->maxMidias * 2;

        Media **newVet = realloc(r->midias, newMax * sizeof( Media *));

        if (newVet == NULL) return;

        r->midias = newVet;
        r->maxMidias = newMax;
    }

    r->midias[r->qntMidias] = media_construct(data, print_fn, free_fn);

    if (r->midias[r->qntMidias] != NULL) r->qntMidias++;
}

// Percorre a lista iterativamente e chama a impressão de todos os seus elementos formatados.
void list_print(List *r)
{
    if (r == NULL) return;

    if (r->qntMidias == 0) { printf("SEM MIDIAS PARA IMPRIMIR\n"); return; }

    printf("IMPRIMINDO MIDIAS FAVORITAS\n\n");

    for (int i = 0; i < r->qntMidias; i++)
    {
        printf("MIDIA %d: ", i +1);
        media_print(r->midias[i]);
        printf("\n");
    }
}

// free lista!
void list_free(List *r)
{  
    for (int i = 0; i < r->qntMidias; i++)
    {
        media_free(r->midias[i]);
    }
     
    free(r->midias);
    free(r);
}