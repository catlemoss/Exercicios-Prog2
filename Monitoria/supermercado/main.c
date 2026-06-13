/*
Exercicio da monitoria de tad opaco de um supermercado simples.
Catarina Lemos
02/06/2026
*/

#include "supermercado.h"

#include <stdio.h>
#include <string.h>

int main()
{
    Supermercado *s = CriarSupermercado();

    char comando[30];

    while (scanf("%29s", comando) == 1)
    {
        if (strcmp(comando, "CADASTRAR") == 0)
        {
            LerCadastroSupermercado(s);
        }

        else if (strcmp(comando, "COMPRAR") == 0)
        {
            LerCompraSupermercado(s);
        }
        
        else if (strcmp(comando, "FORNECEDOR") == 0)
        {
            LerFornecimento(s);
        }
        
        else if (strcmp(comando, "ESTOQUE") == 0)
        {
            ConsultarEstoqueSupermercado(s);
        }
        
        else if (strcmp(comando, "LUCRO") == 0)
        {
            ConsultarLucroSupermercado(s);
        }

        else if (strcmp(comando, "ENCERRAR") == 0) break;
    }

    LiberaSupermercado(s);

    return 0;
}