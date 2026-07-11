/*
Você viajou no tempo por engano e acabou caindo em 2002.
Para sobreviver você terá que trabalhar como programador de uma videolocadora
Catarina Lemos
11/07/2026
*/

#include "locadora.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    tLocadora *locadora = CriarLocadora();

    char opcao[MAX_CARACTERES];
    
    while (scanf("%[^\n]", opcao) == 1)
    {
        if (strcmp(opcao, "Cadastrar") == 0)
        {
            LerCadastroLocadora(locadora);
        }

        else if (strcmp(opcao, "Estoque") == 0)
        {
            OrdenarFilmesLocadora(locadora);
            ConsultarEstoqueLocadora(locadora);
        }

        else if (strcmp(opcao, "Alugar") == 0)
        {
            LerAluguelLocadora(locadora);
        }

        else if (strcmp(opcao, "Devolver") == 0)
        {
            LerDevolucaoLocadora(locadora);
            ConsultarLucroLocadora(locadora);
        }
    }

    DestruirLocadora(locadora);

    return 0;
}