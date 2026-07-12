/*
Implemente um TAD Aluno, opaco. Esse TAD deve ser capaz de retornar se um aluno está aprovado, caso sua média seja
maior ou igual a 7, ou reprovado caso seja menor que 7.
Catarina Lemos
12/07/2026
*/

#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int nAlunos;
    scanf("%d\n", &nAlunos);

    tAluno **alunos = malloc (nAlunos * sizeof(tAluno *));
    if (alunos == NULL) exit (1);

    for (int i = 0; i < nAlunos; i++)
    {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for (int i = 0; i < nAlunos -1; i++)
    {
        for (int j = 0; j < nAlunos -1-i; j++)
        {
            if (ComparaMatricula(alunos[j], alunos[j+1]) > 0)
            {
                tAluno *aux = alunos[j];
                alunos[j] = alunos[j+1];
                alunos[j+1] = aux;
            }
        }
    }

    for (int i = 0; i < nAlunos; i++)
    {
        if (VerificaAprovacao(alunos[i]))
        {
            ImprimeAluno(alunos[i]);
        }
    }

    for (int i = 0; i < nAlunos; i++)
    {
        ApagaAluno(alunos[i]);
    }

    free (alunos);

    return 0;
}