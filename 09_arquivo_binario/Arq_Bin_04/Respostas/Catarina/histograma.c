#include "histograma.h"

#include <stdio.h>
#include <stdlib.h>

struct tHistograma
{
    int *qntPixels;
    int tamBucket;
    int nIntervalos;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos)
{
    int val;

    Histograma *h = (Histograma *) malloc (sizeof (Histograma));

    h->nIntervalos = nIntervalos;
    h->tamBucket = 256 / nIntervalos;

    if (256 % nIntervalos != 0)
    {
        h->tamBucket++;
    }

    h->qntPixels = (int *) calloc (nIntervalos, sizeof (int));

    for (int i = 0; i < (ObterAlturaImagem(img) * ObterLarguraImagem(img)); i++)
    {
        if (ObterTipoImagem(img) == INT)
        {
            val = ((int *) ObterDadosImagem(img))[i];
        }

        else
        {
            val = 255 * ((float *) ObterDadosImagem(img))[i];
        }

        h->qntPixels[val / h->tamBucket]++;
    }

    return h;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma)
{
    for (int i = 0; i < histograma->nIntervalos; i++)
    {
        printf("[%d, %d): %d\n", 
            i * histograma->tamBucket, 
            (i + 1) * histograma->tamBucket, 
            histograma->qntPixels[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma)
{
    if (histograma != NULL)
    {
        free (histograma->qntPixels);
        free (histograma);
    }

    
}