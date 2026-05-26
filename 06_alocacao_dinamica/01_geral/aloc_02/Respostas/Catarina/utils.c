#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * Função que cria uma matriz de inteiros, alocada dinamicamente. Se a alocação falhar, o programa é encerrado.
 * 
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz. 
 * @return Ponteiro para a matriz alocada.
*/
int **CriaMatriz(int linhas, int colunas)
{
    int **mat = malloc (linhas * sizeof (* mat)); // ou int *
    
    if (mat == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return 0;
    }

    for (int i = 0; i < linhas; i++)
    {
        mat[i] = malloc (colunas * sizeof (int));

        if (mat[i] == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            
            for (int j = 0; j < i; j++)
            {
                free(mat[j]);
            }

            free(mat);
            return 0;
        }
    }

    return mat;
}

/**
 * Função que libera a memória alocada para uma matriz de inteiros.
 * 
 * @param matriz Ponteiro para a matriz a ser liberada.
 * @param linhas Número de linhas da matriz.
*/
void LiberaMatriz(int **matriz, int linhas)
{
    for (int i = 0; i < linhas; i++)
    {
        free(matriz[i]);
    }

    free(matriz);
}

/**
 * Função que lê uma matriz de inteiros da entrada padrão.
 * 
 * @param matriz Ponteiro para a matriz a ser lida.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void LeMatriz(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
}

/**
 * Imprime a matriz transposta da matriz dada.
 * 
 * @param matriz Ponteiro para a matriz.
 * @param linhas Número de linhas da matriz.
 * @param colunas Número de colunas da matriz.
*/
void ImprimeMatrizTransposta(int **matriz, int linhas, int colunas)
{
    for (int i = 0; i < colunas; i++)
    {
        for (int j = 0; j < linhas; j++)
        {
            printf("%d", matriz[j][i]);

            if (j < linhas -1) printf(" ");
        }

        printf("\n");
    }
}