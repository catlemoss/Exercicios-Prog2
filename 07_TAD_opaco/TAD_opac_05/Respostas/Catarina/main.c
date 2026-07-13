/*
Vamos simular um simples sistema bancário capaz de fazer
operações de saque, depósito, transferência e abertura de conta.
Catarina Lemos
12/07/2026
*/

#include "banco.h"
#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    tBanco *banco = CriaBanco();

    char opcao;

    while (scanf(" %c", &opcao) == 1)
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