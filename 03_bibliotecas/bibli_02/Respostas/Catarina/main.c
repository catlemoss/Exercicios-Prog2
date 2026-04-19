/*
Um programa que cria uma biblioteca que forneça uma
variedade de funções para manipulação de matrizes.
Catarina Lemos
18/04/2026
*/

#include <stdio.h>

#include "matrix_utils.h"

int main ()
{
    int lin1, col1;
    scanf("%d %d", &lin1, &col1);

    int mat1[lin1][col1];
    matrix_read(lin1, col1, mat1);


    int lin2, col2;
    scanf("%d %d", &lin2, &col2);

    int mat2[lin2][col2];
    matrix_read(lin2, col2, mat2);

    int opcao;

    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");

        scanf(" %d", &opcao);
        printf("\n");

        if (opcao == 6) break;

        if (opcao == 1) // soma
        {
            if (possible_matrix_sum(lin1, col1, lin2, col2))
            {
                int result[lin1][col1];
                matrix_add(lin1, col1, mat1, lin2, col2, mat2, result);
                matrix_print(lin1, col1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }
        }

        if (opcao == 2) // sub
        {
            if (possible_matrix_sub(lin1, col1, lin2, col2))
            {
                int result[lin1][col1];
                matrix_sub(lin1, col1, mat1, lin2, col2, mat2, result);
                matrix_print(lin1, col1, result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }
        }

        if (opcao == 3) // mult
        {
            if (possible_matrix_multiply(col1, lin2))
            {
                int result[lin1][col2];
                matrix_multiply(lin1, col1, mat1, lin2, col2, mat2, result);
                matrix_print(lin1, col2, result);
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                continue;
            }
        }

        if (opcao == 4) // mult por num
        {
            int escalar, numMat;
            scanf("%d %d", &escalar, &numMat);

            if (numMat == 1)
            {
                scalar_multiply(lin1, col1, mat1, escalar);
                matrix_print(lin1, col1, mat1);
            }

            else if (numMat == 2)
            {
                scalar_multiply(lin2, col2, mat2, escalar);
                matrix_print(lin2, col2, mat2);
            }
        }

        if (opcao == 5) //transposta
        {
            int result1[col1][lin1];
            int result2[col2][lin2];

            transpose_matrix(lin1, col1, mat1, result1);
            transpose_matrix(lin2, col2, mat2, result2);

            matrix_print(col1, lin1, result1);
            matrix_print(col2, lin2, result2);
        }
    }

    return 0;
}