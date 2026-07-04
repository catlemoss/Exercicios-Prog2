#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    int linhas;
    int colunas;
    int nBytes;

    Tipo tipoImg;

    void *pixels;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * A função também armazena o número de bytes lidos na estrutura Imagem.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho)
{
    FILE *arq = fopen (caminho, "rb");
    if (arq == NULL) return NULL;

    Imagem *img = malloc (sizeof (Imagem));
    if (img == NULL)
    {
        fclose(arq);
        exit (1);
    }

    img->nBytes = 0;
    img->pixels = NULL;

    size_t lidos;

    // Leia do arquivo 1 bloco do tamanho de um int e guarde dentro de img
    lidos = fread(&img->linhas, sizeof(int), 1, arq);
    img->nBytes += lidos * sizeof(int);

    lidos = fread(&img->colunas, sizeof(int), 1, arq);
    img->nBytes += lidos * sizeof(int);

    lidos = fread(&img->tipoImg, sizeof(int), 1, arq);
    img->nBytes += lidos * sizeof(int);

    int nPix = img->linhas * img->colunas;

    if (img->tipoImg == INT)
    {
        img->pixels = malloc (nPix * sizeof(int));
        if (img->pixels == NULL)
        {
            free (img);
            fclose (arq);
            exit (1);
        }

        lidos = fread (img->pixels, sizeof(int), nPix, arq);
        img->nBytes += lidos * sizeof(int);
    }

    else if (img->tipoImg == FLOAT)
    {
        img->pixels = malloc (nPix * sizeof(float));
        if (img->pixels == NULL)
        {
            free (img);
            fclose (arq);
            exit (1);
        }

        lidos = fread (img->pixels, sizeof(float), nPix, arq);
        img->nBytes += lidos * sizeof(float);
    }

    fclose (arq);

    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    free (img->pixels);
    free (img);
}

/**
 * @brief Função para obter o número de bytes lidos de uma imagem.
 * @param img A imagem.
 * @return O número de bytes lidos.
 */
int ObterNumeroBytesLidos(Imagem *img)
{
    return img->nBytes;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img)
{
    int nPix = img->linhas * img->colunas;

    if (img->tipoImg == INT)
    {
        int *pix = (int *) img->pixels;

        for (int i = 0; i < nPix; i++)
        {
            printf("%d ", pix[i]);
        }
    }

    else if (img->tipoImg == FLOAT)
    {
        float *pix = (float *) img->pixels;

        for (int i = 0; i < nPix; i++)
        {
            printf("%.2f ", pix[i]);
        }
    }

    printf("\n");
}