#include "produto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um produto.
 */
struct Produto
{
    int cod;
    char nome[50];
    float valor;
    int qntVend;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidadeVendida)
{
    tProduto *produto = malloc (sizeof (*produto));
    if (produto == NULL) exit (1);

    produto->cod = codigo;
    produto->qntVend = quantidadeVendida;

    produto->valor = preco;

    strcpy(produto->nome, nome);

    return produto;
}

/**
 * @brief Função para destruir um produto.
 * @param produto Um ponteiro para o produto a ser destruído.
 */
void DestroiProduto(tProduto *produto)
{
    free (produto);
}

/**
 * @brief Função para ler um produto de um arquivo binário.
 * @param arquivo O arquivo de onde o produto será lido.
 * Formato do arquivo: 
 * Código (int) 
 * Nome (string) 
 * Preço (float) 
 * Quantidade (int).
 * @return Um ponteiro para o produto lido.
 */
tProduto *LeProduto(FILE *arquivo)
{
    tProduto *p = malloc (sizeof (tProduto));
    if (p == NULL) exit (1);

    if (fread (&p->cod, sizeof(int), 1, arquivo) != 1) exit (1);
    if (fread (p->nome, sizeof(p->nome), 1, arquivo) != 1) exit (1);
    if (fread (&p->valor, sizeof(float), 1, arquivo) != 1) exit (1);
    if (fread (&p->qntVend, sizeof(int), 1, arquivo) != 1) exit (1);

    p->nome[49] = '\0';

    return p;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco;Quantidade vendida".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;R$ %.2f;%d", 
        produto->cod,
        produto->nome,
        produto->valor,
        produto->qntVend
    );
}

/**
 * @brief Função para obter a quantidade vendida de um produto.
 * @param produto Um ponteiro para o produto.
 * @return A quantidade vendida do produto.
 */
int GetQuantidadeVendidaProduto(tProduto *produto)
{
    return produto->qntVend;
}

/**
 * @brief Função para obter o preço de um produto.
 * @param produto Um ponteiro para o produto.
 * @return O preço do produto.
*/
float GetPrecoProduto(tProduto *produto)
{
    return produto->valor;
}