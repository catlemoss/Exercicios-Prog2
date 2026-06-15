#include "imagem.h"

#include <stdio.h>
#include <stdlib.h>

/*
typedef enum 
{
    FLOAT = 0, 
    INT = 1    
} Tipo;
*/

/**
 * @brief Estrutura para representar uma imagem.
 */
struct tImagem
{
    void *dado;

    Tipo tipoImg;

    int altura;
    int largura;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
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

    fread (&img->altura, sizeof (int), 1, arq);
    fread (&img->largura, sizeof (int), 1, arq);
    fread (&img->tipoImg, sizeof (int), 1, arq);

    if (img->tipoImg == INT)
    {
        img->dado = malloc (sizeof (int) * (img->altura * img->largura));
        fread (img->dado, sizeof (int), (img->altura * img->largura), arq);
    }

    else
    {
        img->dado = malloc (sizeof (float) * (img->altura * img->largura));
        fread (img->dado, sizeof (float), (img->altura * img->largura), arq);   
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
    if (img != NULL)
    {
        free(img->dado);
        free(img);
    }

    
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img)
{
    return img->altura;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img)
{
    return img->largura;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img)
{
    return img->tipoImg;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dfree (histograma);ados da imagem.
 */
void *ObterDadosImagem(Imagem *img)
{
    return img->dado;
}