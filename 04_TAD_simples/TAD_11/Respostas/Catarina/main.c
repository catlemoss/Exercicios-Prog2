/*
Vamos simular uma simplificação de um sistema de demonstração
de resultado operacional para empresas de varejo.
Catarina Lemos
23/05/2026
*/

#include "loja.h"

#include <stdio.h>

int main ()
{
    int nLojas;
    scanf("%d\n", &nLojas);

    // (0 - Sair; 1 – Abrir loja; 2 – Contratar vendedor; 3 – Registrar
    // venda; 4 – Relatório geral).

    int opcao;

    tLoja lojas[nLojas];
    int qntLojas = 0;

    tVendedor vendedor;

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

            vendedor = RegistraVendedor(nome, salario, comissao);

            for (int i = 0; i < nLojas; i++)
            {
                if (VerificaIdLoja(lojas[i], lojaTrabalha))
                {
                    lojas[i] = ContrataVendedor(lojas[i], vendedor);
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

            for (int i = 0; i < nLojas; i++)
            {
                if (VerificaIdLoja(lojas[i], IdLoja))
                {
                    lojas[i] = RegistraVenda(lojas[i], nome, venda);
                    break;       
                }
            }
        }

        else if (opcao == 4)
        {
            for (int i = 0; i < nLojas; i++)
            {
                ImprimeRelatorioLoja(lojas[i]);
                printf("\n");
            }
        }
    }

    return 0;
}