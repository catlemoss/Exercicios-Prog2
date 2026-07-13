#include "banco.h"

#include "conta.h"

#include <stdio.h>
#include <stdlib.h>

struct Banco
{
    tConta **contas;
    int qnt;
    int max;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *b = malloc (sizeof(*b));
    if (b == NULL) exit (1);

    b->qnt = 0;
    b->max = 5;

    b->contas = calloc (5, sizeof(b->contas));
    if (b->contas == NULL) exit (1);

    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qnt; i++)
    {
        DestroiConta(banco->contas[i]);
    }

    free (banco->contas);
    free (banco);
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco)
{
    if (banco->qnt == banco->max)
    {
        int newMax = banco->max *2;

        tConta **newConta = realloc (banco->contas, newMax * sizeof(tConta *));
        if (newConta == NULL) exit (1);

        banco->max = newMax;
        banco->contas = newConta;
    }

    tConta *conta = CriaConta();
    LeConta(conta);

    banco->contas[banco->qnt] = conta;
    banco->qnt++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int id;
    float valor;
    scanf("%d %f\n", &id, &valor);

    for (int i = 0; i < banco->qnt; i++)
    {
        if (VerificaConta(banco->contas[i], id))
        {
            SaqueConta(banco->contas[i], valor);
        }
    }
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int id;
    float valor;
    scanf("%d %f\n", &id, &valor);

    for (int i = 0; i < banco->qnt; i++)
    {
        if (VerificaConta(banco->contas[i], id))
        {
            DepositoConta(banco->contas[i], valor);
        }
    }
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int idD;
    int idO;
    float valor;
    scanf("%d %d %f\n", &idD, &idO, &valor);

    tConta *origem = NULL;
    tConta *destiny = NULL;

    for (int i = 0; i < banco->qnt; i++)
    {
        if (VerificaConta(banco->contas[i], idO))
        {
            origem = banco->contas[i];
        }

        if (VerificaConta(banco->contas[i], idD))
        {
            destiny = banco->contas[i];
        }
    }

    TransferenciaConta(destiny, origem, valor);
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < banco->qnt; i++)
    {
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}
