/*
Você viajou no tempo por engano e acabou caindo em
2002. Para sobreviver você terá que trabalhar como programador de uma videolocadora,
criando um sistema de locação de filmes na linguagem que o dono da loja exige, a
linguagem C. O objetivo é controlar as operações de cadastro de filmes, aluguel de fitas,
devolução de fitas e consulta ao estoque.
Catarina Lemos
03/08/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "locadora.h"

int main()
{
    tLocadora *locadora = CriarLocadora();
    char operacao[50];

    while (scanf("%49s\n", operacao) == 1)
    {
        if (strcmp(operacao, "Cadastrar") == 0)
        {
            LerCadastroLocadora(locadora);
            printf("\n");
        }
        else if (strcmp(operacao, "Alugar") == 0)
        {
            printf("\n");
            LerAluguelLocadora(locadora);
        }
        else if (strcmp(operacao, "Devolver") == 0)
        {
            printf("\n");
            LerDevolucaoLocadora(locadora);
        }
        else if (strcmp(operacao, "Estoque") == 0)
        {
            printf("\n");
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
            scanf("%*c");
        }
    }

    ConsultarLucroLocadora(locadora);
    DestruirLocadora(locadora);

    return 0;
}