#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

typedef void (*Impressao)(void *);

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    int altura, largura;
    int bytesLidos;

    Tipo tipoImg;

    void *pixels;
    int numPix;

    Impressao imprimir;
};

static void imprimeInt(void *pix);
static void imprimeFloat(void *pix);

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

    Imagem *img = calloc (1, sizeof(*img));
    if (img == NULL) exit (1);

    img->bytesLidos += fread (&img->altura, sizeof(img->altura), 1, arq);
    img->bytesLidos += fread (&img->largura, sizeof(img->largura), 1, arq);
    img->bytesLidos += fread (&img->tipoImg, sizeof(img->tipoImg), 1 , arq);

    int qnt = img->altura * img->largura;

    if (img->tipoImg == INT)
    {
        img->numPix = sizeof(int);
        img->imprimir = imprimeInt;
    }

    else if (img->tipoImg == FLOAT)
    {
        img->numPix = sizeof(float);
        img->imprimir = imprimeFloat;
    }

    int qnt = img->altura * img->largura;
    img->pixels = malloc (qnt * img->numPix);

    img->bytesLidos = fread (img->pixels, img->numPix, qnt, arq);

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
    for (int i = 0; i < img->altura; i++)
    {
        char *sep = "";
        for (int j = 0; j < img->largura; j++)
        {
            scanf("%s", sep);
            sep = " ";
            int elem_offset = i * img->largura + j;

            int bytes_offset = img->numPix * elem_offset;

            img->imprimir(img->pixels + bytes_offset);
        }
++++++++++++++++++++++++++
        printf("\n");
    }
}

static void imprimeInt(void *pix)
{
    printf("%d", *(int *) pix);
}

static void imprimeFloat(void *pix)
{
    printf("%.2f", *(float *) pix);
}
