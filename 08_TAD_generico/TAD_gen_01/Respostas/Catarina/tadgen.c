#include "tadgen.h"

#include <stdio.h>
#include <stdlib.h>

struct generic
{
    void *dados;            // vet generico
    Type tipo;              // int ou float
    int nElementos;         // quantos nums tem o vet 
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric* CriaGenerico(Type type, int numElem)
{
    tGeneric *g = malloc (sizeof (tGeneric));
    if (g == NULL) return NULL;

    g->tipo = type;
    g->nElementos = numElem;
    g->dados = NULL;

    if (type == INT)
    {
        g->dados = (int *) malloc (g->nElementos * sizeof (int));
    }

    else if (type == FLOAT)
    {
        g->dados = (float *) malloc (g->nElementos * sizeof (float));
    }

    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric* gen)
{
    free (gen->dados);
    free (gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric* gen)
{
    if (gen == NULL) return;

    printf("Digite o vetor:\n");

    for (int i = 0; i < gen->nElementos; i++)
    {
        if (gen->tipo == INT)
        {
            scanf("%d\n", &((int *) gen->dados)[i]);
        }

        else if (gen->tipo == FLOAT)
        {
            scanf("%f\n", &((float *) gen->dados)[i]);
        }
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric* gen)
{
    if (gen == NULL) return;

    if (gen->tipo == INT)
    {
        int *vet = (int *) gen->dados;

        for (int i = 0; i < gen->nElementos; i++)
        {
            printf("%d", vet[i]);

            if (i < gen->nElementos -1) printf(" ");
        }
    }

    else if (gen->tipo == FLOAT)
    {
        float *vet = (float *) gen->dados;

        for (int i = 0; i < gen->nElementos; i++)
        {
            printf("%.2f", vet[i]);

            if (i < gen->nElementos -1) printf(" ");
        }
    }

    printf("\n");
}