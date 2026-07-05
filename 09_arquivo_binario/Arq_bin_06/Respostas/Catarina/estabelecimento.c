#include "estabelecimento.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um estabelecimento.
 */
struct Estabelecimento
{
    tProduto **produtos;
    int qnt;
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
    
    e->qnt = 0;
    e->max = 0;

    return e;
}

/**
 * @brief Função para destruir um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento a ser destruído.
 */
void DestroiEstabelecimento(tEstabelecimento *estabelecimento)
{
    for (int i = 0; i < estabelecimento->qnt; i++)
    {
        DestroiProduto(estabelecimento->produtos[i]);
    }

    free (estabelecimento->produtos);
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

    if (estabelecimento->qnt == estabelecimento->max)
    {
        int newMax = estabelecimento->max *2;

        tProduto **newProd = realloc (estabelecimento->produtos, newMax * sizeof(tProduto *));
        if (newProd == NULL) exit (1);

        estabelecimento->max = newMax;
        estabelecimento->produtos = newProd;
    }

    estabelecimento->produtos[estabelecimento->qnt] = produto;
    estabelecimento->qnt++;
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
    if (arq == NULL) exit(1);

    int qntProd;

    if ( fread (&qntProd, sizeof(int), 1, arq) != 1)
    {
        fclose(arq);
        exit(1);
    }

    estabelecimento->qnt = qntProd;
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
 * @brief Função para obter o valor total de produtos vendidos em um estabelecimento.
 * @param estabelecimento Um ponteiro para o estabelecimento.
 * @return O valor total de produtos vendidos.
*/
float GetValorTotalVendidoEstabelecimento(tEstabelecimento *estabelecimento)
{
    float precoT = 0;

    for (int i = 0; i < estabelecimento->qnt; i++)
    {
        precoT += GetPrecoProduto(estabelecimento->produtos[i]) * GetQuantidadeVendidaProduto(estabelecimento->produtos[i]);
    }

    return precoT;
}

/**
 * @brief Função para imprimir na tela um relatório de um estabelecimento, cotendo o valor total vendido e a porcentagem de cada produto relativo ao total vendido.
 * Formato: Codigo;Nome;Preco;Quantidade vendida
 * @param estabelecimento Um ponteiro para o estabelecimento.
*/
void ImprimeRelatorioEstabelecimento(tEstabelecimento *estabelecimento)
{
    printf("Valor total vendido: R$ %.2f\n", GetValorTotalVendidoEstabelecimento(estabelecimento));
    printf("Produtos vendidos:\n");
    printf("Codigo;Nome;Preco;Quantidade vendida;Porcentagem\n");

    for (int i = 0; i < estabelecimento->qnt; i++)
    {
        ImprimeProduto(estabelecimento->produtos[i]);

        float perc = GetPrecoProduto(estabelecimento->produtos[i]) *
            GetQuantidadeVendidaProduto(estabelecimento->produtos[i]) / GetValorTotalVendidoEstabelecimento(estabelecimento) * 100;

        printf(";%.2f%%\n", perc);
    }
}