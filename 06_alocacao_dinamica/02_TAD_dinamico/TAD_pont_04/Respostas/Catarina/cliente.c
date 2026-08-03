#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

tCliente *tClienteConstruct()
{
    tCliente *vet = calloc (1, sizeof(*vet));
    if (vet == NULL) exit (1);

    return vet;
}

void tClientePushBack(tCliente *c, tAluno *aluno)
{
    if (c->max == 0)
    {
        c->max = 4;
        c->alunos = malloc (c->max * sizeof(tAluno));
    }

    if (c->qnt == c->max)
    {
        int newMax = c->max *2;

        tAluno **newAluno = realloc (c->alunos, newMax * sizeof(tAluno*));
        if (newAluno == NULL) exit (1);

        c->max = newMax;
        c->alunos = newAluno;
    }

    c->alunos[c->qnt] = aluno;
    c->qnt++;
}

tAluno *tClienteGet(tCliente *c, int i)
{
    return c->alunos[i];
}

int tClienteSize(tCliente *c)
{
    return c->qnt;
}

void tClienteOrganize(tCliente *c)
{
    for (int i = 0; i < c->qnt -1; i++)
    {
        for (int j = 0; j < c->qnt-1-i; j++)
        {
            if (ComparaMatricula(c->alunos[j], c->alunos[j+1]) > 0)
            {
                tAluno *aux = c->alunos[j];
                c->alunos[j] = c->alunos[j+1];
                c->alunos[j+1] = aux;
            }
        }
    }
}

void tClienteDestroy(tCliente *c)
{
    for (int i = 0; i < c->qnt; i++)
    {
        ApagaAluno (c->alunos[i]);
    }

    free (c->alunos);
    free (c);
}