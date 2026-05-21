/*
O objetivo deste desafio é criar um TAD do tipo Matriz que forneça
uma variedade de funçõ es para manipulaçã o de matrizes.
Catarina Lemos
21/05/2026
*/

#include "matrix_utils.h"

#include <stdio.h>

int main ()
{
    tMatrix m1, m2, R;
    int l1, c1, l2, c2;

    scanf("%d %d", &l1, &c1);
    m1 = MatrixCreate(l1, c1);
    m1 = MatrixRead(m1);

    scanf("%d %d", &l2, &c2);
    m2 = MatrixCreate(l2, c2);
    m2 = MatrixRead(m2);

    int opcao;

    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        scanf("%d", &opcao);

        if (opcao == 6) break;

        if (opcao == 1)
        {
            if (!PossibleMatrixSum(m1, m2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }

            else
            {
                R = MatrixAdd(m1, m2);
                MatrixPrint(R);
            }
        }

        else if (opcao == 2)
        {
            if (!PossibleMatrixSub(m1, m2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            }

            else
            {
                R = MatrixSub(m1, m2);
                MatrixPrint(R);
            }
        }

        else if (opcao == 3)
        {
            if (!PossibleMatrixMultiply(m1, m2))
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            }

            else
            {
                R = MatrixMultiply(m1, m2);
                MatrixPrint(R);
            }
        }

        else if (opcao == 4)
        {
            int scalar, nMat;
            scanf("%d %d", &scalar, &nMat);

            if (nMat == 1)
            {
                m1 = MatrixMultiplyByScalar(m1, scalar);
                MatrixPrint(m1);
            }

            else
            {
                m2 = MatrixMultiplyByScalar(m2, scalar);
                MatrixPrint(m2);
            }
        }

        else if (opcao == 5)
        {
            R = TransposeMatrix(m1);
            MatrixPrint(R);

            R = TransposeMatrix(m2);
            MatrixPrint(R);
        }
    }

    return 0;
}