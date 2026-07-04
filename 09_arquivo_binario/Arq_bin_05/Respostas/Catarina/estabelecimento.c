#include "estabelecimento.h"

#include "vector.h"
#include "produto.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento
{
    tProduto **produtos;
    int nProdutos;
    int max;
};

/**
 * @brief Função para criar um novo estabelecimento.
 * @return Um ponteiro para o estabelecimento recém-criado. Se houver erro na alocação, o programa é encerrado.
 */
tEstabelecimento *CriaEstabelecimento()
{
    tEstabelecimento *e = malloc (sizeof (tEstabelecimento));
    if (e == NULL) exit (1);

    e->produtos = NULL;

    e->nProdutos = 0;
    e->max = 0;

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    for (int i = 0; i < estabelecimento->nProdutos; i++)
    {
        DestroiProduto(estabelecimento->produtos[i]);
    }

    DestroiProduto(estabelecimento->produtos);
    free (estabelecimento);
}

/**
 * @brief Função para adicionar um produto a um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @param produto Um ponteiro para o produto a ser adicionado.
 */
void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto)
{
    if (estabelecimento->max == 0)
    {
        estabelecimento->max = 4;
        estabelecimento->produtos = malloc (estabelecimento->max * sizeof(tProduto *));
    }

    if (estabelecimento->nProdutos == estabelecimento->max)
    {
        int newMax = estabelecimento->max *2;

        tProduto **newProd = realloc (estabelecimento->produtos, newMax * sizeof(tProduto *));
        if (newProd == NULL) exit(1);
        
        estabelecimento->produtos = newProd;
        estabelecimento->max = newMax;
    }

    estabelecimento->produtos[estabelecimento->nProdutos] = produto;
    estabelecimento->nProdutos++;
}

/**
 * @brief Função para ler um estabelecimento de um arquivo binário.
 * Inicialmente, deverá ser lido o nome do arquivo binário pela entrada padrão.
 * O arquivo binário deverá ser composto por um inteiro que representa a quantidade de produtos no estabelecimento, seguido pelos produtos.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser lido.
 */
void LeEstabelecimento(tEstabelecimento *estabelecimento)
{
    char nomeArq[50];
    scanf("%49s", nomeArq);

    FILE *arq = fopen(nomeArq, "rb");
    if (arq == NULL)
    {
        exit(1);
    }

    int qntProd;

    if ( fread (&qntProd, sizeof(int), 1, arq) != 1)
    {
        fclose(arq);
        exit(1);
    }

    estabelecimento->nProdutos = qntProd;
    estabelecimento->max = qntProd;

    estabelecimento->produtos = malloc (qntProd * sizeof(tProduto *));
    if (estabelecimento->produtos == NULL)
    {
        fclose(arq);
        exit(1);
    }

    for (int i = 0; i < qntProd; i++)
    {
        estabelecimento->produtos[i] = LeProduto(arq);

        if (estabelecimento->produtos[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                DestroiProduto(estabelecimento->produtos[j]);
            }

            free(estabelecimento->produtos);
            fclose(arq);
            exit(1);
        }
    }

    fclose(arq);
}

/**
 * @brief Função para imprimir produtos que estão faltando em um estabelecimento no seguinte formato: Codigo;Nome;Preco
 * @param estabelecimento Um ponteiro para o estabelecimento.
 */
void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");

    int imprimiu = 0;

    for (int i = 0; i < estabelecimento->nProdutos; i++)
    {
        if (!TemEstoqueProduto(estabelecimento->produtos[i]))
        {
            ImprimeProduto(estabelecimento->produtos[i]);
            imprimiu++;
        }
    }

    if (!imprimiu) printf("Nao ha produtos em falta!\n");
}
