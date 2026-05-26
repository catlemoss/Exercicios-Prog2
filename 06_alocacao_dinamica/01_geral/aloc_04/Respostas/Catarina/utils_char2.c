#include "utils_char2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Cria um vetor de caracteres que consegue armazenar uma string de tamanho igual a "TAM_PADRAO", alocado dinamicamente.
 * Neste caso, a string deve ser inicializada com todas as suas "TAM_PADRAO" posições com "_", e a última posição deve conter '\0'.
 * Se houver erro na alocação, imprime uma mensagem de erro e encerra o programa.
 * 
 * @return Ponteiro para o vetor criado.
 */
char *CriaVetorTamPadrao()
{
    char *string = malloc((TAM_PADRAO + 1) * sizeof(char));

    if (string == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    memset(string, '_', TAM_PADRAO);
    string[TAM_PADRAO] = '\0';

    return string;
}

/**
 * Aumenta o tamanho de um vetor alocado dinamicamente
 * O vetor deve ser aumentado para conseguir alocar mais "TAM_PADRAO" caracteres (o vetor só pode ter tamanhos múltiplos de "TAM_PADRAO")
 * Preencha as novas posições com "_", e lembre-se que a última deve conter '\0'.
 * 
 * @param tamanhoantigo Tamanho do vetor a ser modificado
 * @return Ponteiro para o novo vetor.
 */
char *AumentaTamanhoVetor(char* vetor, int tamanhoantigo)
{
   
    int newTamanho = tamanhoantigo + TAM_PADRAO;

    char *temp = realloc(vetor, (newTamanho + 1) * sizeof (char));

    if (temp == NULL)
    {
       printf("Erro ao realocar memoria.\n");
        return NULL;
    }

    vetor = temp;

    for (int i = tamanhoantigo; i < newTamanho; i++)
    {
        vetor[i] = '_';
    }

    vetor[newTamanho] = '\0';

    return vetor;
}

/**
 * Lê uma string do tamanho especificado até um enter ser apertado.
 * Caso seja necessário alterar o tamanho do vetor, o tamanho deve ser atualizado para que o programa
 * saiba o novo tamanho do vetor.
 *
 * @param vetor Ponteiro para o vetor a ser lido.
 * @param tamanho* Ponteiro para uma variável do tipo inteiro que armazena o tamanho atual do vetor.
 * @return Um ponteiro para o vetor lido.
*/
char* LeVetor(char *vetor, int *tamanho)
{
    int i = 0;
    int c;          // int porque getchar pode retornar EOF

    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (i == *tamanho)
        {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            *tamanho = *tamanho + TAM_PADRAO;
        }

        vetor[i] = c;
        i++;
    }

    for (; i < *tamanho; i++)
    {
        vetor[i] = '_';
    }

    vetor[*tamanho] = '\0';

    return vetor;
}

/**
 * Imprime a string
 * 
 * @param vetor Ponteiro para o vetor a ser imprimido.
*/
void ImprimeString(char *vetor)
{
    int tam = strlen(vetor);

    for (int i = 0; i < tam; i++)
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