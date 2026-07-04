#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    int altura;
    int largura;
    int nBytes;

    Tipo tipoImg;

    void *dado;
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

    if (arq == NULL)
    {
        printf("Erro na leitura do arquivo.\n");
        exit(0);                            // serve para ver q o problema é a leitura do arq
    }

    Imagem *img = (Imagem *) malloc (sizeof (Imagem));

    if (img == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    img->nBytes = 0;

    fread (&img->altura, sizeof (int), 1, arq);
    img->nBytes += sizeof(int);

    fread (&img->largura, sizeof (int), 1, arq);
    img->nBytes += sizeof(int);

    fread (&img->tipoImg, sizeof (int), 1, arq);
    img->nBytes += sizeof(int);

    if (img->tipoImg == INT)
    {
        img->dado = malloc (sizeof (int) * (img->altura * img->largura));
        fread (img->dado, sizeof (int), (img->altura * img->largura), arq);
        img->nBytes += sizeof(int);
    }

    else
    {
        img->dado = malloc (sizeof (float) * (img->altura * img->largura));
        fread (img->dado, sizeof (float), (img->altura * img->largura), arq);
        img->nBytes += sizeof(int);  
    }

    fclose(arq);                            // ponteiro para o arquivo
    return img;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img)
{
    free (img->dado);
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
    int nPix = img->altura * img->largura;

    if (img->tipoImg == INT)
    {
        int *pix = (int *) img->dado;

        for (int i = 0; i < nPix; i++)
        {
            printf("%d ", pix[i]);
        }
    }

    else if (img->tipoImg == FLOAT)
    {
        float *pix = (float *) img->dado;

        for (int i = 0; i < nPix; i++)
        {
            printf("%.2f ", pix[i]);
        }
    }

    printf("\n");
}