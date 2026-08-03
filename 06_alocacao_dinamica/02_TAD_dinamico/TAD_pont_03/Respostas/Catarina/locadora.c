#include <stdio.h>
#include <stdlib.h>

#include "locadora.h"

/**
 * @brief Cria uma nova instância de tLocadora e inicializa filme como NULL, numFilmes como 0 e lucro como 0.
 * 
 * @return tLocadora* Ponteiro para a nova instância de tLocadora criada ou encerra o programa caso não haja memória suficiente.
 */
tLocadora* CriarLocadora ()
{
    tLocadora *l = calloc (1, sizeof(*l));
    if (l == NULL) exit (1);

    l->filme = NULL;
    l->numFilmes = 0;
    l->lucro = 0;

    return l;
}

/**
 * @brief Destrói uma instância de tLocadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser destruída.
 */
void DestruirLocadora (tLocadora* locadora)
{
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        DestruirFilme (locadora->filme[i]);
    }

    free (locadora->filme);
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
    for (int i = 0; i < locadora->numFilmes; i++)
    {
        if (EhMesmoCodigoFilme(locadora->filme[i], codigo)) return 1;
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
    if (VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme)))
    {
        printf("Filme ja cadastrado no estoque\n");
        DestruirFilme(filme);
        return;
    }

    tFilme **newVetor = realloc (locadora->filme, (locadora->numFilmes + 1) * sizeof(*locadora->filme));
    if (newVetor == NULL) exit(1);

    locadora->filme = newVetor;
    
    locadora->filme[locadora->numFilmes] = filme;
    locadora->numFilmes++;

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
    int codigo;

    while (scanf("%d,", &codigo) == 1)
    {
        tFilme *filme = CriarFilme();

        LeFilme(filme, codigo);
        CadastrarFilmeLocadora(Locadora, filme);
    }

    scanf("%*c"); // consome o #
}

/**
 * @brief Aluga um ou mais filmes da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem alugados.
 * @param qntCodigos Número de códigos de filmes a serem alugados.
 */
void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int qntCodigos)
{
    int qntAlu = 0;
    int custoTotal = 0;

    for (int i = 0; i < qntCodigos; i++)
    {
        int find = 0;

        for (int j = 0; j < locadora->numFilmes; j++)
        {
            if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i]))
            {
                find = 1;

                if (ObterQtdEstoqueFilme(locadora->filme[j]) > 0)
                {
                    AlugarFilme(locadora->filme[j]);
                    qntAlu++;
                    custoTotal += ObterValorFilme(locadora->filme[j]);
                }
                else
                {
                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" nao disponivel no estoque. Volte mais tarde.\n");
                }

                break;
            }
        }

        if (!find) printf("Filme %d nao cadastrado.\n", codigos[i]);
    }

    if (qntAlu > 0)
    {
        printf("Total de filmes alugados: %d com custo de R$%d\n", qntAlu, custoTotal);
    }
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerAluguelLocadora (tLocadora* locadora)
{
    int codigos[100];
    int qnt = 0;
    int cod;

    while (qnt < 100 && scanf("%d", &cod) == 1)
    {
        codigos[qnt] = cod;
        qnt++;
    }

    AlugarFilmesLocadora(locadora, codigos, qnt);
    scanf("%*c");
}

/**
 * @brief Devolve um ou mais filmes alugados da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 * @param codigos Vetor contendo os códigos dos filmes a serem devolvidos.
 * @param qntCodigos Número de códigos de filmes a serem devolvidos.
 */
void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int qntCodigos)
{
    for (int i = 0; i < qntCodigos; i++)
    {
        int find = 0;

        for (int j = 0; j < locadora->numFilmes; j++)
        {
            if (EhMesmoCodigoFilme(locadora->filme[j], codigos[i]))
            {
                find = 1;

                if (ObterQtdAlugadaFilme(locadora->filme[j]) > 0)
                {
                    DevolverFilme(locadora->filme[j]);

                    printf("Filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(" Devolvido!\n");

                    locadora->lucro += ObterValorFilme(locadora->filme[j]);
                }
                else
                {
                    printf("Nao e possivel devolver o filme %d - ", ObterCodigoFilme(locadora->filme[j]));
                    ImprimirNomeFilme(locadora->filme[j]);
                    printf(".\n");
                }

                break;
            }
        }

        if (!find) printf("Filme %d nao cadastrado.\n", codigos[i]);
    }
}

/**
 * @brief Lê os dados de devolução de um ou mais filmes e os devolve na locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void LerDevolucaoLocadora (tLocadora* locadora)
{
    int codigos[100];
    int qnt = 0;
    int cod;

    while (qnt < 100 && scanf("%d", &cod) == 1)
    {
        codigos[qnt] = cod;
        qnt++;
    }

    DevolverFilmesLocadora(locadora, codigos, qnt);
    scanf("%*c");
}

/**
 * @brief Ordena os filmes cadastrados na locadora por ordem alfabética.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser atualizada.
 */
void OrdenarFilmesLocadora (tLocadora* locadora)
{
    for (int i = 0; i < locadora->numFilmes -1; i++)
    {
        for (int j = 0; j < locadora->numFilmes -1-i; j++)
        {
            if (CompararNomesFilmes(locadora->filme[j], locadora->filme[j+1]) > 0)
            {
                tFilme *aux = locadora->filme[j];
                locadora->filme[j] = locadora->filme[j+1];
                locadora->filme[j+1] = aux;
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

    OrdenarFilmesLocadora(locadora);

    for (int i = 0; i < locadora->numFilmes; i++)
    {
        printf("%d - ", ObterCodigoFilme(locadora->filme[i]));
        ImprimirNomeFilme(locadora->filme[i]);
        printf(" Fitas em estoque: %d\n", ObterQtdEstoqueFilme(locadora->filme[i]));
    }
}

/**
 * @brief Consulta o lucro da locadora.
 * 
 * @param locadora Ponteiro para a instância de tLocadora a ser consultada.
 */
void ConsultarLucroLocadora (tLocadora* locadora)
{
    if (locadora->lucro > 0) printf("\nLucro total R$%d\n", locadora->lucro);
}