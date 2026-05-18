#include "locadora.h"
#include "filme.h"

#include <stdio.h>
#include <string.h>

/*
#define MAX_FILMES 100

typedef struct Locadora {
    tFilme filme[MAX_FILMES]; 
    int numFilmes; 
    int lucro; 
} tLocadora;
*/

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora ()
{
    tLocadora l;

    l.numFilmes = 0;
    l.lucro = 0;
    
    return l;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado (tLocadora locadora, int codigo)
{
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        if (ehMesmoCodigoFilme(locadora.filme[i], codigo)) return 1;
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
*/
tLocadora cadastrarFilmeLocadora (tLocadora locadora, tFilme filme)
{
    if (verificarFilmeCadastrado(locadora, obterCodigoFilme(filme)))
    {
        printf("Filme ja cadastrado no estoque\n");
    }

    else
    {
        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        printf("\n");

        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
    }

    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora (tLocadora locadora)
{
    int codigo;

    while (scanf(" %d,", &codigo) == 1)
    {
        tFilme filme;

        filme = leFilme(codigo);
        locadora = cadastrarFilmeLocadora(locadora, filme);
    }

    scanf(" %*c ");

    return locadora;
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param qntCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora (tLocadora locadora, int* codigos, int qntCodigos)
{
    int qntAlugados = 0;
    int custo = 0;

    for (int i = 0; i < qntCodigos; i++)
    {
        int achei = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {
                achei = 1;

                if (obterQtdEstoqueFilme(locadora.filme[j]) > 0)
                {
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    custo += obterValorFilme(locadora.filme[j]);

                    qntAlugados++;
                }

                else 
                {
                    printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }

                break; // achamos filme
            }
        }

        if (!achei) printf("Filme %d nao cadastrado.\n", codigos[i]);
    }

    if (qntAlugados > 0)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qntAlugados, custo);
    }

    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora (tLocadora locadora)
{
    int codigos[MAX_FILMES];
    int qntCodigos = 0;
    int cod;

    while (scanf(" %d ", &cod) == 1)
    {
        codigos[qntCodigos++] = cod;
    }

    scanf(" %*c ");

    locadora = alugarFilmesLocadora(locadora, codigos, qntCodigos);

    return locadora;
}

/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param qntCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora (tLocadora locadora, int* codigos, int qntCodigos)
{
    for (int i = 0; i < qntCodigos; i++)
    {
        int achei = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {
            if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i]))
            {
                achei = 1;

                if (obterQtdAlugadaFilme(locadora.filme[j]) > 0)
                {
                    locadora.filme[j] = devolverFilme(locadora.filme[j]);

                    printf("Filme %d - ", codigos[i]);
                    imprimirNomeFilme(locadora.filme[j]);
                    printf("Devolvido!\n");

                    locadora.lucro += obterValorFilme(locadora.filme[j]);
                }

                else 
                {
                    printf("Nao e possivel devolver o filme %d - ", obterCodigoFilme(locadora.filme[j]));
                    imprimirNomeFilme(locadora.filme[j]);
                    printf(".\n");
                }

                break;
            }
        }

        if (!achei) printf("Filme %d nao cadastrado.\n", codigos[i]);
    }

    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora (tLocadora locadora)
{
    int codigos[MAX_FILMES];
    int qntCodigos = 0;
    int cod;

    while (scanf(" %d ", &cod) == 1)
    {
        codigos[qntCodigos++] = cod;
    }

    scanf(" %*c ");

    locadora = devolverFilmesLocadora(locadora, codigos, qntCodigos);

    return locadora;
}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora (tLocadora locadora)
{
    tFilme aux;

    for (int i = 0; i < locadora.numFilmes - 1; i++)
    {
        for (int j = i + 1; j < locadora.numFilmes; j++)
        {
            if (compararNomesFilmes(locadora.filme[i], locadora.filme[j]) > 0)
            {
                aux = locadora.filme[i];
                locadora.filme[i] = locadora.filme[j];
                locadora.filme[j] = aux;
            }
        }
    }

    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora (tLocadora locadora)
{
    printf("~ESTOQUE~\n");

    for (int i = 0; i < locadora.numFilmes; i++)
    {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora (tLocadora locadora)
{
    if (locadora.lucro > 0)
    {
        printf("\n");
        printf("Lucro total R$%d\n", locadora.lucro);
    }
}