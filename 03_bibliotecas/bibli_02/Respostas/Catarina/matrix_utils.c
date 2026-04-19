#include <stdio.h>

#include "matrix_utils.h"

// le mat
void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// printa mat
void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    for (int i = 0; i < rows; i++)
    {
        printf("|");

        for (int j = 0; j < cols; j++)
        {
            printf("%d", matrix[i][j]);

            if (j < cols - 1) printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

// pode somar?
int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    return (rows1 == rows2 && cols1 == cols2);
}

// pode sub?
int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    return (rows1 == rows2 && cols1 == cols2);
}

// pode mult?
int possible_matrix_multiply(int cols1, int rows2)
{
    return (cols1 == rows2);
}

// soma
void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// sub
void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// mult
void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    for (int i = 0; i < rows1; i++)             // zerando mat
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// transposta
void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }
}

// mult por um num
void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = matrix[i][j] * scalar;
        }
    }
}