#include "departamento.h"

#include <stdio.h>
#include <string.h>
#include <math.h>

/*
#define STRING_MAX 101 // número máximo de caracteres por string

typedef struct Departamento {
    char nome [STRING_MAX];     // nome do departamento
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX]; // nomes dos cursos do departamento
    int m1, m2, m3;     // médias de notas dos cursos do departamento
    char diretor [STRING_MAX];    // nome do diretor do departamento
    float media_geral;
} tDepartamento;
*/

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor)
{
    tDepartamento d;

    strcpy(d.c1, c1);
    strcpy(d.c2, c2);
    strcpy(d.c3, c3);
    strcpy(d.nome, nome);
    d.m1 = m1;
    d.m2 = m2;
    d.m3 = m3;
    strcpy(d.diretor, diretor);
    d.media_geral = (float)calculaMediaGeralDepartamento(d);

    return d;
}

/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void imprimeAtributosDepartamento (tDepartamento depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n", calculaDesvioPadraoDepartamento(depto));
    printf("\n");
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int validaMediaDepartamento (int media)
{
    return 0 <= media && media <= 10;
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    double variancia = (pow(depto.m1 - depto.media_geral, 2) + pow(depto.m2 - depto.media_geral, 2) + pow(depto.m3 - depto.media_geral, 2));
 
    return sqrt(variancia / 3.0);
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double calculaMediaGeralDepartamento(tDepartamento depto)
{
    return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param d Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1 - i; j++)
        {
            if (d[j].media_geral < d[j + 1].media_geral)
            {
                tDepartamento aux = d[j];
                d[j] = d[j + 1];
                d[j + 1] = aux;
            }
        }
    }
}