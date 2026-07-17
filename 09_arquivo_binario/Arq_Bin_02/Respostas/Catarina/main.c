/*
Este exercício consiste em implementar funções para salvar um vetor que
contém elementos de um tipo específico em um arquivo binário.
Catarina Lemos
17/07/2026
*/

#include "base_alunos.h"

#include <stdio.h>

int main ()
{
    tBaseAlunos *base = CriarBaseAlunos();

    char nomeArq[50];
    scanf("%s", nomeArq);

    LerBaseAlunos(base, nomeArq);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;
}