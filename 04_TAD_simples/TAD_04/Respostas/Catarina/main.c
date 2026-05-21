/*
Um TAD Aluno que deve ser capaz de retornar se um aluno está aprovado, caso sua média seja
maior ou igual a 7, ou reprovado caso seja menor que 7.
Catarina Lemos
21/05/2026
*/

#include "aluno.h"

#include <stdio.h>
#include <string.h>

int main ()
{
    int nAlunos;
    scanf("%d\n", &nAlunos);

    tAluno vetorAlunos[nAlunos];

    for (int i = 0; i < nAlunos; i++)
    {
        vetorAlunos[i] = LeAluno();
    }

    // ordenar por matricula
    for (int i = 0; i < nAlunos - 1; i++)
    {
        for (int j = 0; j < nAlunos - 1; j++)
        {
            if (ComparaMatricula(vetorAlunos[j], vetorAlunos[j + 1]) == 1)
            {
                tAluno aux = vetorAlunos[j];
                vetorAlunos[j] = vetorAlunos[j + 1];
                vetorAlunos[j + 1] = aux;
            }
        }
    }

    // imprimir aprovados
    for (int i = 0; i < nAlunos; i++)
    {
        if (VerificaAprovacao(vetorAlunos[i]))
        {
            ImprimeAluno(vetorAlunos[i]);
        }
    }

    return 0;
}