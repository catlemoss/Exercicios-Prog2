/*
Vamos simular um simples sistema bancário capaz de fazer
operações de saque, depósito, transferência e abertura de conta.
Catarina Lemos
04/08/2026 (meu mesversario amo)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banco.h"

int main ()
{
    char opcao;

    tBanco *banco = CriaBanco();

    while (scanf(" %c\n", &opcao) == 1)
    {
        if (opcao == 'F') break;

        else if (opcao == 'S')
        {
            SaqueContaBanco(banco);
        }

        else if (opcao == 'D')
        {
            DepositoContaBanco(banco);
        }

        else if (opcao == 'T')
        {
            TransferenciaContaBanco(banco);
        }

        else if (opcao == 'A')
        {
            AbreContaBanco(banco);
        }

        else if (opcao == 'R')
        {
            ImprimeRelatorioBanco(banco);
        }
    }

    DestroiBanco(banco);

    return 0;
}