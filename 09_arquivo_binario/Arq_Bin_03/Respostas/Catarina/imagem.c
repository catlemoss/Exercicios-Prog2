#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    int altura, largura;
    int bytesLidos;

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
    if (arq == NULL) exit (1);

    Imagem *img = malloc (sizeof (*img));
    if (img == NULL) exit (1);

    img->bytesLidos = 0;
    img->pixels = NULL;

    img->bytesLidos += fread (&img->altura, sizeof(int), 1, arq);
    img->bytesLidos += fread (&img->largura, sizeof(int), 1, arq);
    img->bytesLidos += fread (&img->tipoImg, sizeof(int), 1 , arq);

    int qnt = img->altura * img->largura;

    if (img->tipoImg == INT)
    {
        img->pixels = malloc (qnt * sizeof(int));
        if (img->pixels  == NULL) { fclose(arq); exit (1); }

        img->bytesLidos += fread (img->pixels, sizeof(int), qnt, arq);
    }

    else if (img->tipoImg == FLOAT)
    {
        img->pixels = malloc (qnt * sizeof(float));
        if (img->pixels == NULL) { fclose(arq); exit (1); }

        img->bytesLidos += fread (img->pixels, sizeof(float), qnt, arq);
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
    return img->bytesLidos;
}

/**
 * @brief Função para imprimir uma imagem.
 * @param img A imagem.
 */
void ImprimirImagem(Imagem *img)
{
    int qnt = img->altura * img->largura;

    if (img->tipoImg == INT)
    {
        int *pixels = (int *) img->pixels;

        for (int i = 0; i < qnt; i++)
        {
            printf("%d ", pixels[i]);
        }
    }

    else if (img->tipoImg == FLOAT)
    {
        float *pixels = (float *) img->pixels;

        for (int i = 0; i < qnt; i++)
        {
            printf("%.2f ", pixels[i]);
        }
    }
}