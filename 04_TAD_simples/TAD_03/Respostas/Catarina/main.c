/*
Você viajou no tempo por engano e acabou caindo em 2002 e agora precisa trabalhar numa locadora.
Catarina Lemos
18/05/2026 (aniversário da Manu!)
*/

#include "locadora.h"

#include <stdio.h>
#include <string.h>

int main ()
{
    tLocadora locadora;
    char comando[MAX_CARACTERES];

    locadora = criarLocadora();

    while (scanf(" %s ", comando) == 1)
    {
        if (strcmp(comando, "#") == 0) continue;

        if (strcmp(comando, "Cadastrar") == 0)
        {
            locadora = lerCadastroLocadora(locadora);
        }

        else if (strcmp(comando, "Alugar") == 0)
        {
            locadora = lerAluguelLocadora(locadora);
        }

        else if (strcmp(comando, "Devolver") == 0)
        {
            locadora = lerDevolucaoLocadora(locadora);
        }

        else if (strcmp(comando, "Estoque") == 0)
        {
            locadora = ordenarFilmesLocadora(locadora);
            printf("\n");
            
            consultarEstoqueLocadora(locadora);
        }
    }
  
    consultarLucroLocadora(locadora);

    return 0;
}