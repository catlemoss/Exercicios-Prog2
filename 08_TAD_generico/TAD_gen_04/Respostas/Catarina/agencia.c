#include "agencia.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    int num;
    char *nome;
    tConta **contas;
    int qnt;
    int max;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *a = malloc (sizeof (tAgencia));
    if (a == NULL)
    {
        printf("Erro ao alocar memoria para a agencia.\n");
        exit (1);
    }

    a->nome = malloc (50 * sizeof (char));
    if (a->nome == NULL) exit (1);

    a->num = 0;
    a->contas = NULL;
    a->qnt = 0;
    a->max = 0;

    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *a = (tAgencia *) agencia;
    
    for (int i = 0; i < a->qnt; i++)
    {
        DestroiConta(a->contas[i]);
    }

    free (a->contas);
    free (a->nome);
    free (a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]\n", &agencia->num, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    if (agencia->max == 0)
    {
        agencia->max = 4;
        agencia->contas = malloc (agencia->max * sizeof (tConta *));
    }

    if (agencia->qnt == agencia->max)
    {
        int newMax = agencia->max *2;

        tConta **newData = realloc (agencia->contas, newMax * sizeof (tConta *));
        if (newData == NULL) exit (1);

        agencia->max = newMax;
        agencia->contas = newData;
    }

    agencia->contas[agencia->qnt] = conta;
    agencia->qnt++;
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    return numAgencia == agencia2->num;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia (tAgencia *agencia)
{
    float total = 0;

    for (int i = 0; i < agencia->qnt; i++)
    {
        total += GetSaldoConta(agencia->contas[i]);
    }

    return total / agencia->qnt;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("\tNome: %s\n", agencia->nome);
	printf("\tNumero: %d\n", agencia->num);
	printf("\tNumero de contas cadastradas: %d\n", agencia->qnt);
	printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}