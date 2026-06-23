#include "relatorio.h"

#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/
void ImprimeRelatorio(Vector *alunos)
{
    float soma = 0;
    int aprovados = 0;
    int fem = 0;
    int masc = 0;
    int outros = 0;

    int nAlunos = VectorSize(alunos);

    for (int i = 0; i < nAlunos; i++)
    {
        data_type alune = VectorGet(alunos, i);

        soma += GetNotaAluno(alune);

        if (GetNotaAluno(alune) >= 6) aprovados++;

        if (GetGeneroAluno(alune) == 'F') fem++;
        else if (GetGeneroAluno(alune) == 'M') masc++;
        else outros++;
    }

    float media = (float) soma / nAlunos;
    float percAprovados = (float) aprovados / nAlunos * 100;
    float percFem = (float) fem / nAlunos * 100;
    float percMasc = (float) masc / nAlunos * 100;
    float percOutros = (float) outros / nAlunos * 100;

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", percAprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", percMasc);
    printf("Feminino: %.2f%%\n", percFem);
    printf("Outro: %.2f%%\n", percOutros);
}