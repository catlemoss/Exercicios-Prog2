/*
Este exercício consiste em implementar funçõ es para salvar e ler um vetor
de um tipo específico em um arquivo biná rio.
Catarina Lemos
02/07/2026
*/

#include "aluno.h"

#include <stdio.h>

int main()
{
    printf("Digite o numero de alunos: ");
    int numeroAlunos;
    scanf("%d", &numeroAlunos);

    Aluno **alunos = CriaVetorAlunos(numeroAlunos);

    LeAlunos(alunos, numeroAlunos);
    SalvaAlunosBinario(alunos, "alunos.bin", numeroAlunos);
    LiberaAlunos(alunos, numeroAlunos);

    Aluno **alunosCarregados = CriaVetorAlunos(numeroAlunos);

    CarregaAlunosBinario(alunosCarregados, "alunos.bin");
    ImprimeAlunos(alunosCarregados, numeroAlunos);
    LiberaAlunos(alunosCarregados, numeroAlunos);

    return 0;
}