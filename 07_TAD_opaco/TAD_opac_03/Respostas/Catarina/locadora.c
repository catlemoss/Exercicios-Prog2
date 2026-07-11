#include "locadora.h"

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILMES 100

struct Locadora
{
    tFilme *filmes[MAX_FILMES];
    int nFilmes;
    int lucro;
};

static tFilme *BuscarFilmePorCodigo(tLocadora *locadora, int codigo);

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *l = calloc (1, sizeof(*l));
    if (l == NULL) exit (1);

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    for (int i = 0; i < locadora->nFilmes; i++)
    {
        DestruirFilme (locadora->filmes[i]);
    }

    free (locadora);
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser verificada.
 * @param codigo Código do filme a ser verificado.
 * @return int 1 se o filme está cadastrado, 0 caso contrário.
 */
int VerificarFilmeCadastrado (tLocadora* locadora, int codigo)
{
    for (int i = 0; i < locadora->nFilmes; i++)
    {
        if (EhMesmoCodigoFilme(locadora->filmes[i], codigo))
        {
            return 1;
        }
    }

    return 0;
}

/**
 * @brief Cadastra um novo filme na locadora caso ele não esteja cadastrado.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param filme Ponteiro para o filme a ser cadastrado.
 */
void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme)
{
    for (int i = 0; i < locadora->nFilmes; i++)
    {
        if (EhMesmoCodigoFilme(locadora->filmes[i], ObterCodigoFilme(filme)))
        {
            printf("Filme ja cadastrado no estoque\n");
            DestruirFilme(filme);
            return;
        }
    }

    if (locadora->nFilmes >= MAX_FILMES)
    {
        DestruirFilme(filme);
        return;
    }

    locadora->filmes[locadora->nFilmes++] = filme;

    printf("Filme cadastrado %d - ", ObterCodigoFilme(filme));
    ImprimirNomeFilme(filme);
    printf("\n");
}

/**
 * @brief Lê os dados de cadastro de um filme e o cadastra na locadora.
 * 
 * @param Locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerCadastroLocadora (tLocadora* Locadora)
{
    while (1)
    {
        int codigo;
        char c;

        if (scanf("%d,", &codigo) == 1)
        {
            tFilme *newFilme = CriarFilme();

            LeFilme(newFilme, codigo);
            CadastrarFilmeLocadora(Locadora, newFilme);
        }

        else if (scanf(" %c", &c) == 1 && c == '#')
        {
            getchar();
            break;
        }
    }
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
    int qntAlug = 0;
    int custo = 0;

    for (int i = 0; i < quantidadeCodigos; i++)
    {
        tFilme *filme = BuscarFilmePorCodigo(locadora, codigos[i]);

        if (filme == NULL)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }

        if (ObterQtdEstoqueFilme(filme) == 0)
        {
            printf("Filme %d - ", ObterCodigoFilme(filme));
            ImprimirNomeFilme(filme);
            printf(" nao disponivel no estoque. Volte mais tarde.\n");
        }

        else
        {
            AlugarFilme(filme);

            qntAlug++;
            custo += ObterValorFilme(filme);
        }
    }

    if (qntAlug == 0) return;
    if (qntAlug > 0) printf("Total de filmes alugados: %d com custo de R$%d\n\n", qntAlug, custo);
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{
    int alug[100];
    int lidos = 0;

    while (lidos < 100 && scanf("%d", &alug[lidos]) == 1) lidos++;

    AlugarFilmesLocadora(locadora, alug, lidos);
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos)
{
     for (int i = 0; i < quantidadeCodigos; i++)
    {
        tFilme *filme = BuscarFilmePorCodigo(locadora, codigos[i]);

        if (filme == NULL)
        {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
            continue;
        }

        if (ObterQtdAlugadaFilme(filme) == 0)
        {
            printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme(filme));
            ImprimirNomeFilme(filme);
            printf(".\n");
        }

        else
        {
            DevolverFilme(filme);
            locadora->lucro += ObterValorFilme(filme);

            printf("Filme %d - ", ObterCodigoFilme(filme));
            ImprimirNomeFilme(filme);
            printf(" Devolvido!\n");
        }
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora)
{
    int dev[100];
    int lidos = 0;

    while (lidos < 100 && scanf("%d", &dev[lidos]) == 1) lidos++;

    DevolverFilmesLocadora(locadora, dev, lidos);
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
    for (int i = 0; i < locadora->nFilmes -1; i++)
    {
        for (int j = 0; j < locadora->nFilmes -1-i; j++)
        {
            if (CompararNomesFilmes(locadora->filmes[j], locadora->filmes[j+1]) > 0)
            {
                tFilme *aux = locadora->filmes[j];
                locadora->filmes[j] = locadora->filmes[j+1];
                locadora->filmes[j+1] = aux;
            }
        }
    }
}

/**
 * @brief Consulta o estoque de filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarEstoqueLocadora (tLocadora* locadora)
{
    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora->nFilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filmes[i]));
        ImprimirNomeFilme(locadora->filmes[i]);

        printf(" Fitas em estoque: %d\n",ObterQtdEstoqueFilme(locadora->filmes[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    printf("Lucro total R$%d\n\n", locadora->lucro);
}

static tFilme *BuscarFilmePorCodigo(tLocadora *locadora, int codigo)
{
    for (int i = 0; i < locadora->nFilmes; i++)
    {
        if (EhMesmoCodigoFilme(locadora->filmes[i], codigo))
        {
            return locadora->filmes[i];
        }
    }

    return NULL;
}