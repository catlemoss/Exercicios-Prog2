/*
Implemente um TAD Aluno, alocado dinamicamente.
Catarina Lemos
03/08/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cliente.h"

int main ()
{
    tCliente *c = tClienteConstruct();

    int nAlunos;
    scanf("%d\n", &nAlunos);

    tAluno *a;

    for (int i = 0; i < nAlunos; i++)
    {
        a = CriaAluno();
        LeAluno(a);

        tClientePushBack(c, a);
    }

    tClienteOrganize(c);

    for (int i = 0; i < tClienteSize(c); i++)
    {
        if (VerificaAprovacao(tClienteGet(c, i)))
        {
            ImprimeAluno(tClienteGet(c, i));
        }
    }

    tClienteDestroy(c);

    return 0;
}