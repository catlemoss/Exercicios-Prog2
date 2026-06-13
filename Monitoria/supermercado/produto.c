#include "produto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto
{
    int codigo;
    char nome[MAX_CARACTERES + 1];
    float valor;
    int qntComprada;
    int qntEstoque;
};

Produto* CriarProduto()
{
    Produto *p = malloc(sizeof(Produto));

    if (p == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    p->codigo = 0;
    p->nome[0] = '\0';
    p->valor = 0.0;
    p->qntComprada = 0;
    p->qntEstoque = 0;

    return p;
}

void LeProduto(Produto *p, int codigo)
{
    if (p == NULL) return;

    p->codigo = codigo;
    p->qntComprada = 0;

    scanf("%20s", p->nome);
    scanf("%f %d", &p->valor, &p->qntEstoque);
}

void LiberaProduto(Produto* p)
{
    free(p);
}

int ObterCodigoProduto(Produto* p)
{
    return p->codigo;
}

void ImprimirNomeProduto(Produto* p)
{
    printf("%s", p->nome);
}

float ObterValorProduto(Produto* p)
{
    return p->valor;
}

int ObterQtdEstoqueProduto(Produto* p)
{
    return p->qntEstoque;
}

int ObterQtdCompradaProduto(Produto* p)
{
    return p->qntComprada;
}

int EhMesmoCodigoProduto(Produto* p, int codigo)
{
    return p->codigo == codigo;
}

void ComprarProduto(Produto* p)
{
    if (p->qntEstoque > 0)
    {
        p->qntComprada++;
        p->qntEstoque--;
    }
}

void AumentaEstoque(Produto* p, int qtdFornecida)
{
    p->qntEstoque += qtdFornecida;
}

int CompararNomesProdutos(Produto* produto1, Produto* produto2)
{
    int resultado = strcmp(produto1->nome, produto2->nome);

    if (resultado > 0) return 1;
    if (resultado < 0) return -1;

    return 0;
}