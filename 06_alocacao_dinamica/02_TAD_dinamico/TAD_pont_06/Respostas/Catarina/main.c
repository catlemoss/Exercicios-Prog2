/*
O objetivo deste desafio é criar um TAD do tipo Matriz que
forneça uma variedade de funçõ es para manipulaçã o de matrizes.
Catarina Lemos
04/08/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "matrix_utils.h"

void menu ()
{
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: ");
}

int main ()
{
    int lin1, col1;
    scanf("%d %d", &lin1, &col1);

    tMatrix *mat1 = MatrixCreate(lin1, col1);
    MatrixRead(mat1);


    int lin2, col2;
    scanf("%d %d", &lin2, &col2);

    tMatrix *mat2 = MatrixCreate(lin2, col2);
    MatrixRead(mat2);

    int opcao;

    while (1)
    {
        menu();

        scanf(" %d", &opcao);
        printf("\n");

        if (opcao == 6) break;

        else if (opcao == 1) // soma
        {
            if (PossibleMatrixSum(mat1, mat2))
            {
                tMatrix *result = MatrixAdd(mat1, mat2);
                MatrixPrint(result);

                MatrixFree(result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }

        else if (opcao == 2) // sub
        {
            if (PossibleMatrixSub(mat1, mat2))
            {
                tMatrix *result = MatrixSub(mat1, mat2);
                MatrixPrint(result);

                MatrixFree(result);
            }
            else
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
        }

        else if (opcao == 3) // mult
        {
            if (PossibleMatrixMultiply(mat1, mat2))
            {
                tMatrix *result = MatrixMultiply(mat1, mat2);
                MatrixPrint(result);

                MatrixFree(result);
            }
            else
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
        }

        else if (opcao == 4) // mult por num
        {
            int escalar, numMat;
            scanf("%d %d", &escalar, &numMat);

            if (numMat == 1)
            {
                tMatrix *result = MatrixMultiplyByScalar(mat1, escalar);

                MatrixFree(mat1);
                mat1 = result;

                MatrixPrint(mat1);
            }

            else if (numMat == 2)
            {
                tMatrix *result = MatrixMultiplyByScalar(mat2, escalar);

                MatrixFree(mat2);
                mat2 = result;

                MatrixPrint(mat2);
            }
        }

        else if (opcao == 5) //transposta
        {
            tMatrix *result1 = TransposeMatrix(mat1);
            tMatrix *result2 = TransposeMatrix(mat2);

            MatrixPrint(result1);
            MatrixPrint(result2);

            MatrixFree(result1);
            MatrixFree(result2);
        }
    }

    MatrixFree(mat1);
    MatrixFree(mat2);

    return 0;
}