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
    float preco;
    int qnt;
};

/**
 * @brief Função para criar um novo produto.
 * @param codigo O código do produto.
 * @param nome O nome do produto.
 * @param preco O preço do produto.
 * @param quantidade A quantidade do produto em estoque.
 * @return Um ponteiro para o produto recém-criado. Se houver erro na alocação de memória, a função aborta o programa.
 */
tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade)
{
    tProduto *p = malloc (sizeof (tProduto));
    if (p == NULL) exit (1);

    p->cod = codigo;
    p->preco = preco;
    p->qnt = quantidade;

    strcpy(p->nome, nome);

    return p;
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
    if (arquivo == NULL) exit (1);

    tProduto *p = malloc (sizeof (tProduto));
    if (p == NULL) exit (1);

    if (fread(&p->cod, sizeof(int), 1, arquivo) != 1)
    {
        free (p);
        return NULL;
    }

    if (fread(p->nome, sizeof(p->nome), 1, arquivo) != 1)
    {
        free (p);
        return NULL;
    }

    if (fread(&p->preco, sizeof(float), 1, arquivo)!= 1)
    {
        free (p);
        return NULL;
    }
    
    if (fread(&p->qnt, sizeof(int), 1, arquivo)!= 1)
    {
        free (p);
        return NULL;
    }

    p->nome[49] = '\0';

    return p;
}

/**
 * @brief Função para verificar se um produto tem estoque.
 * @param produto Um ponteiro para o produto.
 * @return 1 se o produto tem estoque, 0 caso contrário.
 */
int TemEstoqueProduto(tProduto *produto)
{
    return produto->qnt > 0;
}

/**
 * @brief Função para imprimir um produto no formato "Codigo;Nome;Preco".
 * @param produto Um ponteiro para o produto a ser impresso.
 */
void ImprimeProduto(tProduto *produto)
{
    printf("%d;%s;%.2f\n", produto->cod, produto->nome, produto->preco);
}