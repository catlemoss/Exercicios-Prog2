#include "media.h"

#include <stdio.h>
#include <stdlib.h>

typedef void (*PrintFunction)(void* data);
typedef void (*FreeFunction)(void* data);

struct Media
{
    void *dado;
    PrintFunction print_fn;
    FreeFunction free_fn;
};

/**
 * @brief Constrói uma nova estrutura de mídia encapsulando os ponteiros e funções recebidos.
 * Esta função é agnóstica ao tipo específico, servindo como invólucro para Músicas, Filmes ou Jogos.
 * @param dado Ponteiro genérico (void*) para o item específico.
 * @param print_fn Função associada para imprimir o dado genérico.
 * @param free_fn Função associada para liberar a memória do dado genérico.
 * @return Ponteiro para a estrutura Media alocada.
 */
Media *media_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    Media *m = malloc(sizeof(Media));

    if (m == NULL) return NULL;

    m->dado = dado;
    m->print_fn = print_fn;
    m->free_fn = free_fn;

    return m; 
}

/**
 * @brief Invoca a função de impressão interna contida na estrutura Media.
 * @param m Ponteiro para a estrutura Media que será impressa.
 */
void media_print(Media* m)
{
    if (m == NULL) return;

    m->print_fn(m->dado);
}

/**
 * @brief Invoca a função de liberação interna do dado e desaloca a estrutura Media.
 * @param m Ponteiro para a estrutura Media a ser destruída.
 */
void media_free(Media* m)
{
    if (m == NULL) return;

    m->free_fn(m->dado);
    free (m);
}