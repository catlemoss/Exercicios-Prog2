/*
Vamos simular um simples sistema de um caixa eletrônico capaz de
fazer operações de saque e depósito numa conta.
Catarina Lemos
21/05/2026
*/

#include "conta.h"

#include <stdio.h>
#include <string.h>

int main ()
{
    int maxContas;
    scanf("%d\n", &maxContas);

    /*
        0 - sair; 
        1 - saque; 
        2 - depósito; 
        3 – cadastro de usuário e conta; 
        4 - relatório).
    */

    int operacao;

    tConta vetorContas[maxContas];

    while (scanf("%d\n", &operacao) == 1)
    {
        if (operacao == 0) break;

        else if (operacao == 1)
        {
            int numConta;
            float valor;

            scanf("%d %f\n", &numConta, &valor);

            vetorContas[numConta -1] = SaqueConta(vetorContas[numConta -1], valor);
        }

        else if (operacao == 2)
        {
            int numConta;
            float valor;

            scanf("%d %f\n", &numConta, &valor);

            vetorContas[numConta -1] = DepositoConta(vetorContas[numConta -1], valor);
        }

        else if (operacao == 3)
        {
            tConta conta;
            tUsuario user;

            scanf("%s %s %d\n", user.nome, user.cpf, &conta.numero);

            user = CriaUsuario(user.nome, user.cpf);

            vetorContas[conta.numero -1] = CriaConta(conta.numero, user);
        }

        else if (operacao == 4)
        {
            printf("===| Imprimindo Relatorio |===\n");

            for (int i = 0; i < maxContas; i++)
            {
                ImprimeConta(vetorContas[i]);
            }
        }
    }

    return 0;
}