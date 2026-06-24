#include "banco.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar um banco.
 */
struct Banco
{
    char *nome;
    tAgencia **agencias;
    int qnt;
    int max;
};

/**
 * @brief Função para criar um novo banco.
 * @return Um ponteiro para o novo banco criado. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tBanco *CriaBanco()
{
    tBanco *b = malloc (sizeof (tBanco));
    if (b == NULL)
    {
        printf("Erro ao alocar memoria para o banco.\n");
        exit (1);
    }

    b->nome = malloc (50 * sizeof (char));
    b->agencias = NULL;
    b->qnt = 0;
    b->max = 0;

    return b;
}

/**
 * @brief Função para destruir um banco.
 * @param banco O banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qnt; i++)
    {
        DestroiAgencia(banco->agencias[i]);
    }

    free (banco->nome);
    free (banco->agencias);
    free (banco);
}

/**
 * @brief Função para ler o nome de um banco.
 * @param banco O banco a ser lido.
 */
void LeBanco(tBanco *banco)
{
    scanf(" %[^\n]\n", banco->nome);
}

/**
 * @brief Função para adicionar uma agência a um banco.
 * @param banco O banco.
 * @param agencia A agência a ser adicionada.
 */
void AdicionaAgencia(tBanco *banco, tAgencia *agencia)
{
    if (banco->max == 0)
    {
        banco->max = 4;
        banco->agencias = malloc (banco->max * sizeof (tAgencia *));
    }

    if (banco->qnt == banco->max)
    {
        int newMax = banco->max *2;

        tAgencia **newAgencia = realloc (banco->agencias, newMax * sizeof (tAgencia *));

        banco->max = newMax;
        banco->agencias = newAgencia;
    }

    banco->agencias[banco->qnt] = agencia;
    banco->qnt++;
}

/**
 * @brief Função para inserir uma conta em uma agência pertencente ao banco.
 * @param banco O banco.
 * @param numAgencia O número da agência.
 * @param cliente A conta a ser inserida.
 * @pre A agência deve pertencer ao banco.
*/
void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente)
{
    for (int i = 0; i < banco->qnt; i++)
    {
        if (ComparaAgencia(numAgencia, banco->agencias[i]))
        {
            AdicionaConta(banco->agencias[i], cliente);
        }
    }
}

/**
 * @brief Função para imprimir o relatório de um banco, com o nome do banco e a lista de agências.
 * @param banco O banco.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for (int i = 0; i < banco->qnt; i++)
    {
        ImprimeDadosAgencia(banco->agencias[i]);
        printf("\n");
    }
}