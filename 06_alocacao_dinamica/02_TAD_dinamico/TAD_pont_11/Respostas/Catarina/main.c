#include <stdio.h>
#include <stdlib.h>

#include "loja.h"

int main ()
{
    int nLojas;
    scanf("%d\n", &nLojas);

    // (0 - Sair; 1 – Abrir loja; 2 – Contratar vendedor; 3 – Registrar venda; 4 – Relatório geral).

    int opcao;

    tLoja *lojas[nLojas];
    int qntLojas = 0;

    while (1)
    {
        scanf("%d\n", &opcao);

        if (opcao == 0) break;

        else if (opcao == 1)
        {
            int id;
            float aluguel;

            scanf("%d %f\n", &id, &aluguel);

            lojas[qntLojas] = AbreLoja(id, aluguel);
            qntLojas++;
        }

        else if (opcao == 2)
        {
            char nome[50];
            float salario;
            float comissao;
            int lojaTrabalha;

            scanf("%s %f %f\n", nome, &salario, &comissao);
            scanf("%d\n", &lojaTrabalha);

            tVendedor *vendedor = RegistraVendedor(nome, salario, comissao);

            for (int i = 0; i < qntLojas; i++)
            {
                if (VerificaIdLoja(lojas[i], lojaTrabalha))
                {
                    ContrataVendedor(lojas[i], vendedor);
                    break;
                }
            }
        }

        else if (opcao == 3)
        {
            int IdLoja;
            char nome[50];
            float venda;

            scanf("%d %s %f\n", &IdLoja, nome, &venda);

            for (int i = 0; i < qntLojas; i++)
            {
                if (VerificaIdLoja(lojas[i], IdLoja))
                {
                    RegistraVenda(lojas[i], nome, venda);
                    break;       
                }
            }
        }

        else if (opcao == 4)
        {
            for (int i = 0; i < qntLojas; i++)
            {
                ImprimeRelatorioLoja(lojas[i]);
                printf("\n");
            }
        }
    }

    for (int i = 0; i < qntLojas; i++)
    {
        ApagaLoja(lojas[i]);
    }
    
    return 0;
}