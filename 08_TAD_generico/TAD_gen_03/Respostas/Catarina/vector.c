#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    data_type *dado;
    int qnt;
    int max;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct()
{
    Vector *v = malloc (sizeof (Vector));
    if (v == NULL) return NULL;

    v->dado = NULL;
    v->qnt = 0;
    v->max = 0;

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val)
{
    if (v->max == 0)
    {
        v->max = 4;
        v->dado = malloc (v->max * sizeof (data_type));
    }

    if (v->qnt == v->max)
    {
        int newMax = v->max * 2;

        data_type *newVet = realloc (v->dado, newMax * sizeof (data_type));
        if (newVet == NULL) return;

        v->max = newMax;
        v->dado = newVet;
    }

    v->dado[v->qnt] = val;
    v->qnt++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i)
{
    return v->dado[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v)
{
    return v->qnt;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for (int i = 0; i < v->qnt; i++)
    {
        destroy(v->dado[i]);
    }

    free (v->dado);
    free (v);
}