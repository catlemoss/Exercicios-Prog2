/*
Crie um programa que leia uma matriz alocada dinamicamente. Ao
final do programa, deverá ser imprimido na tela a matriz transposta.
Catarina Lemos
26/05/2026
*/

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int linhas, colunas;
    scanf("%d %d\n", &linhas, &colunas);

    int **mat = CriaMatriz(linhas, colunas);

    LeMatriz(mat, linhas, colunas);

    ImprimeMatrizTransposta(mat, linhas, colunas);

    LiberaMatriz(mat, linhas);

    return 0;
}