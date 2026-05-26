#include "utils_char.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria um vetor de caracteres de tamanho especificado, alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas posições com "_"
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @param tamanho Tamanho do vetor a ser criado.
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetor(int tamanho)
{
    char *string = malloc((tamanho + 1) * sizeof (char));

    if (string == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    memset(string, '_', tamanho);
    string[tamanho] = '\0';

    return string;
}

/**
 * Lê uma string do tamanho especificado.
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
*/
void LeVetor(char *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%c", &vetor[i]);

        if (vetor[i] == '\n')
        {
            vetor[i++] = '_';
        }
    }
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho Tamanho do vetor a ser lido.
 * @return Média dos valores do vetor.
*/
void ImprimeString(char *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

/**
 * Libera a memória alocada para um vetor de caracteres.
 * 
 * @param vetor Ponteiro para o vetor a ser liberado.
*/
void LiberaVetor(char *vetor)
{
    free(vetor);
}