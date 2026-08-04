/*
Crie um TAD do tipo Funcionario, que armazena um Id e um
salário.
Catarina Lemos
04/08/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"

int main ()
{
    int nEmpresas;
    scanf("%d\n", &nEmpresas);

    tEmpresa **empresas = malloc (nEmpresas * sizeof(*empresas));

    for (int i = 0; i < nEmpresas; i++)
    {
        tEmpresa *e = CriaEmpresa();
        LeEmpresa(e);

        empresas[i] = e;
    }

    for (int i = 0; i < nEmpresas; i++)
    {
        ImprimeEmpresa(empresas[i]);

        if (i < nEmpresas -1) printf("\n");
    }

    for (int i = 0; i < nEmpresas; i++)
    {
        ApagaEmpresa(empresas[i]);
    }

    free (empresas);

    return 0;
}