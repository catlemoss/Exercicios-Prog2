/*
Crie um TAD do tipo Funcionario, que armazena um Id e um
salá rio. Em seguida, crie um TAD do tipo Empresa, que armazena um Id ú nico, a
quantidade de funcioná rios e um vetor de funcionários.
Catarina Lemos
23/05/2026
*/

#include "empresa.h"

#include <stdio.h>

int main ()
{
    int nEmpresas;
    scanf("%d\n", &nEmpresas);

    tEmpresa empresas[nEmpresas];

    for (int i = 0; i < nEmpresas; i++)
    {
        empresas[i] = leEmpresa();
    }

    for (int i = 0; i < nEmpresas; i++)
    {
        imprimeEmpresa(empresas[i]);

        if (i < nEmpresas -1) printf("\n");
    }

    return 0;
}