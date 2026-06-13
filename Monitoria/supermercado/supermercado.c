#include "supermercado.h"

#include <stdio.h>
#include <stdlib.h>

#define TAM_INICIAL 10

struct Supermercado
{
    Produto **produtos;
    int qntAlocada;
    int numProdutos;
    float lucro;
};

static Produto* BuscarProduto(Supermercado *s, int codigo)
{
    for (int i = 0; i < s->numProdutos; i++)
    {
        if (EhMesmoCodigoProduto(s->produtos[i], codigo))
        {
            return s->produtos[i];
        }
    }

    return NULL;
}

Supermercado* CriarSupermercado()
{
    Supermercado *s = malloc( sizeof( Supermercado));

    if (s == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    s->produtos = NULL;
    s->qntAlocada = 0;
    s->numProdutos = 0;
    s->lucro = 0.0;

    return s;
}

void LiberaSupermercado(Supermercado* s)
{
    if (s == NULL) return;

    for (int i = 0; i < s->numProdutos; i++)
    {
        LiberaProduto(s->produtos[i]);
    }

    free(s->produtos);
    free(s);
}

int VerificarProdutoCadastrado(Supermercado* s, int codigo)
{
    if (s == NULL) return 0;

    return BuscarProduto(s, codigo) != NULL;
}

void LerCadastroSupermercado(Supermercado* s)
{
    int codigo;
    scanf("%d", &codigo);

    Produto *p = CriarProduto();
    LeProduto(p, codigo);

    CadastrarProdutoSupermercado(s, p);
}

void CadastrarProdutoSupermercado(Supermercado *s, Produto *p)
{
    if (s == NULL || p == NULL) return;

    if (VerificarProdutoCadastrado(s, ObterCodigoProduto(p)))
    {
        LiberaProduto(p);
        return;
    }

    if (s->numProdutos == s->qntAlocada)
    {
        int newQntAloc;

        if (s->qntAlocada == 0)
        {
            newQntAloc = TAM_INICIAL;
        }

        else newQntAloc = s->qntAlocada * 2;

        Produto **novoVetor = realloc( s->produtos, newQntAloc * sizeof(Produto*));

        if (novoVetor == NULL)
        {
            printf("Erro ao realocar memoria.\n");
            LiberaProduto(p);
            LiberaSupermercado(s);
            return;
        }

        s->produtos = novoVetor;
        s->qntAlocada = newQntAloc;
    }

    s->produtos[s->numProdutos] = p;
    s->numProdutos++;

    ImprimirNomeProduto(p);
    printf(" foi cadastrado(a)\n");
}

void ComprarProdutoSupermercado(Supermercado* s, int codigo)
{
    Produto *p = BuscarProduto(s, codigo);

    if (p == NULL)
    {
        printf("Codigo nao cadastrado no supermercado\n");
        return;
    }

    if (ObterQtdEstoqueProduto(p) <= 0)
    {
        ImprimirNomeProduto(p);
        printf(" sem estoque\n");
        return;
    }

    ComprarProduto(p);
    s->lucro += ObterValorProduto(p);

    ImprimirNomeProduto(p);
    printf(" foi comprado(a)\n");
}

void LerCompraSupermercado(Supermercado* s)
{
    int qntCompras;
    int codigo;

    scanf("%d", &qntCompras);

    for (int i = 0; i < qntCompras; i++)
    {
        scanf("%d", &codigo);
        ComprarProdutoSupermercado(s, codigo);
    }
}

void FornecerProdutoSupermercado(Supermercado* s, int codigo, int qtdFornecida)
{
    Produto *p = BuscarProduto(s, codigo);

    if (p == NULL)
    {
        printf("Codigo nao cadastrado no supermercado\n");
        return;
    }

    AumentaEstoque(p, qtdFornecida);

    ImprimirNomeProduto(p);
    printf(" teve estoque aumentado\n");
}

void LerFornecimento(Supermercado* s)
{
    int codigo;
    int qtdFornecida;

    scanf("%d %d", &codigo, &qtdFornecida);

    FornecerProdutoSupermercado(s, codigo, qtdFornecida);
}

void OrdenarProdutosSupermercado(Supermercado* s)
{
    for (int i = 0; i < s->numProdutos - 1; i++)
    {
        for (int j = 0; j < s->numProdutos - i - 1; j++)
        {
            if (CompararNomesProdutos(s->produtos[j], s->produtos[j + 1]) > 0)
            {
                Produto *aux = s->produtos[j];
                s->produtos[j] = s->produtos[j + 1];
                s->produtos[j + 1] = aux;
            }
        }
    }
}

void ConsultarEstoqueSupermercado(Supermercado* s)
{
    OrdenarProdutosSupermercado(s);

    for (int i = 0; i < s->numProdutos; i++)
    {
        printf("%d - ", ObterCodigoProduto(s->produtos[i]));

        ImprimirNomeProduto(s->produtos[i]);

        printf(" - %d\n", ObterQtdEstoqueProduto(s->produtos[i]));
    }
}

void ConsultarLucroSupermercado(Supermercado* s)
{
    printf("Lucro do supermercado: %.2f\n", s->lucro);
}