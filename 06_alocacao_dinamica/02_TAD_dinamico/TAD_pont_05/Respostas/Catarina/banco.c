#include <stdio.h>
#include <stdlib.h>

#include "banco.h"

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco()
{
    tBanco *b = calloc (1, sizeof(*b));
    if (b == NULL) exit (1);

    b->contas = malloc (5 * sizeof(tConta));

    b->qtdContas = 0;
    b->contasAlocadas = 5;

    return b;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco)
{
    for (int i = 0; i < banco->qtdContas; i++)
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
    if (banco->qtdContas == banco->contasAlocadas)
    {
        tConta **newConta = realloc (banco->contas, (banco->contasAlocadas + 1) * sizeof(*newConta));

        banco->contas = newConta;
    }

    tConta *conta = CriaConta();
    LeConta(conta);

    banco->contas[banco->qtdContas] = conta;
    banco->qtdContas++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco)
{
    int idConta;
    float valor;

    scanf("%d %f\n", &idConta, &valor);

    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], idConta))
        {
            SaqueConta(banco->contas[i], valor);
        }
    }   
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco)
{
    int idConta;
    float valor;

    scanf("%d %f\n", &idConta, &valor);

    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], idConta))
        {
            DepositoConta(banco->contas[i], valor);
        }
    }  
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco)
{
    int idDestino;
    int idOrigem;
    float valor;

    scanf("%d %d %f\n", &idDestino, &idOrigem, &valor);

    for (int i = 0; i < banco->qtdContas; i++)
    {
        for (int j = 0; j < banco->qtdContas; j++)
        {
            if (VerificaConta(banco->contas[i], idDestino) && VerificaConta(banco->contas[j], idOrigem))
            {
                TransferenciaConta(banco->contas[i], banco->contas[j], valor);
            }
        }
    }   
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");

    for (int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}
