#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    DataType *dado;
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
    Vector *vet = calloc (1, sizeof(*vet));
    if (vet == NULL) exit (1);

    return vet;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, DataType val)
{
    if (v->max == 0)
    {
        v->max = 4;
        v->dado = malloc (v->max * sizeof(DataType));
    }

    if (v->qnt == v->max)
    {
        int newMax = v->max *2;

        DataType *newData = realloc (v->dado, newMax * sizeof(DataType));

        v->max = newMax;
        v->dado = newData;
    }

    v->dado[v->qnt] = val;
    v->qnt++;
}

/**
 * @brief Remove o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
*/
void VectorRemove(Vector *v, int i)
{
    for (int i = 0; i < v->qnt; i++)
    {
        for (int j = i; j < v->qnt -1-i; j++)
        {
            v->dado[j] = v->dado[j+1];
        }

        v->qnt--;
    }
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return DataType Elemento do vetor
*/
DataType VectorGet(Vector *v, int i)
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
 * @brief Troca os elementos i e j do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do primeiro elemento
 * @param j Índice do segundo elemento
*/
void VectorSwap(Vector *v, int i, int j)
{
    DataType aux = v->dado[i];
    v->dado[i] = v->dado[j];
    v->dado[j] = aux;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(DataType))
{
    for (int i = 0; i < v->qnt; i++)
    {
        destroy (v->dado[i]);
    }

    free (v->dado);
    free (v);
}