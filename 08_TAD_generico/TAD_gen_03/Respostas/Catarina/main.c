/*
Crie um TAD genérico para representar a estrutura de dados Vector
de C++.
Catarina Lemos
23/06/2026
*/

#include "relatorio.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int alunosCad;
    scanf("%d\n", &alunosCad);

    Vector *alunos = VectorConstruct();

    for (int i = 0; i < alunosCad; i++)
    {
        tAluno *a = CriaAluno();
        LeAluno(a);

        VectorPushBack(alunos, a);
    }

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos, DestroiAluno);

    return 0;
}