/*
Para este exercício, reutilize a estrutura de dados genérica Vector
desenvolvida no exercício anterior. Sua tarefa é gerar um mini relatório com os
dados de um determinado banco, que serão fornecidos na entrada do programa.
Catarina Lemos
24/06/2026
*/

#include "banco.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    tBanco *banco = CriaBanco();
    LeBanco(banco);

    while (1)
    {
        char opc;
        scanf(" %c", &opc);

        if (opc == 'A')
        {
            // cadastrar uma agencia

            tAgencia *agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }

        else if (opc == 'C')
        {
            // cadastrar uma conta

            tConta *conta = CriaConta();
            LeConta(conta);

            int numAgencia;
            scanf("%d\n", &numAgencia);

            InsereContaBanco(banco, numAgencia, conta);
        }

        else if (opc == 'F') break;
    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);

    return 0;
}