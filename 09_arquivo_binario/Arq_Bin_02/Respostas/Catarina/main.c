/*
Este exercício consiste em implementar funções para salvar um vetor que
contém elementos de um tipo específico em um arquivo binário.
Catarina Lemos
02/07/2026
*/

#include "base_alunos.h"

#include <stdio.h>

int main ()
{
    char nomeArq[100];
    scanf("%99s", nomeArq);

    tBaseAlunos *base = CriarBaseAlunos();

    LerBaseAlunos(base, nomeArq);

    float media = GetCoeficienteRendimentoMedioBaseAlunos(base);
    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", media);

    DestruirBaseAlunos(base);

    return 0;
}