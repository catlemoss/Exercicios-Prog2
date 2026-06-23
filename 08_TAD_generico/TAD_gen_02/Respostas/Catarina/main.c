/*
Seu trabalho é criar um TAD genérico que prepara uma mensagem para
ser enviada para o destino, gerando um pacote que será enviado.
Catarina Lemos
23/06/2026
*/

#include "gerenciadorpacotes.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    tGerenciador *g = CriaGerenciador();

    while (1)
    {
        printf("Escolha uma opcao:\n");
        printf("\t(1) Cadastrar um novo pacote\n");
        printf("\t(2) Imprimir um pacote especifico\n");
        printf("\t(3) Imprimir todos os pacotes e sair\n");

        int opc;
        scanf("%d", &opc);

        if (opc == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:\n");

            int tipo, nElementos;
            scanf("%d %d", &tipo, &nElementos);

            if (tipo != 0 && tipo != 1)
            {
                printf("Digite um tipo valido!\n");
                continue;
            }
            
            tPacote *p = CriaPacote((Type) tipo, nElementos);
            LePacote(p);
            AdicionaPacoteNoGerenciador(g, p);
        }

        else if (opc == 2)
        {
            int indx;
            scanf("%d\n", &indx);

            ImprimirPacoteNoIndice(g, indx);
        }

        else if (opc == 3)
        {
            ImprimirTodosPacotes(g);
            break;
        }

        else printf("Escolha uma opcao valida para o menu!\n");
    }

    DestroiGerenciador(g);

    return 0;
}