#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "departamento.h"

/**
 * @brief Cria uma estrutura, alocada dinamicamente, que possui os campos de um departamento. 
 * Lembre-se de inicializar os ponteiros com NULL e as variáveis númericas com -1.
 * 
 * @return Um ponteiro para uma estrutura de um Departamento.
 */
tDepartamento* CriaDepartamento()
{
    tDepartamento *d = malloc (sizeof(*d));
    if (d == NULL) exit (1);

    d->c1 = NULL;
    d->c2 = NULL;
    d->c3 = NULL;

    d->nome = NULL;
    d->diretor = NULL;

    d->m1 = -1;
    d->m2 = -1;
    d->m3 = -1;

    d->media_geral = -1;

    return d;
}

/**
 * @brief Preenche os dados de uma estrutura departamento a partir de valores nomes dos cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param c1 Nome de um dos cursos do departamento.
 * @param c2 Nome de um dos cursos do departamento.
 * @param c3 Nome de um dos cursos do departamento.
 * @param nome Nome do departamento.
 * @param m1 Média do curso c1.
 * @param m2 Média do curso c2.
 * @param m3 Média do curso c3.
 * @param diretor Nome do diretor.
 */
void PreencheDadosDepartamento(tDepartamento* depto, char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor)
{
    depto->c1 = malloc((strlen(c1)+1) * sizeof(char));
    depto->c2 = malloc((strlen(c2)+1) * sizeof(char));
    depto->c3 = malloc((strlen(c3)+1) * sizeof(char));

    depto->nome = malloc((strlen(nome)+1) * sizeof(char));
    depto->diretor = malloc((strlen(diretor)+1) * sizeof(char));

    strcpy(depto->c1, c1);
    strcpy(depto->c2, c2);
    strcpy(depto->c3, c3);

    strcpy(depto->nome, nome);
    strcpy(depto->diretor, diretor);

    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;

    depto->media_geral = (float)CalculaMediaGeralDepartamento(depto);
}

void LiberaMemoriaDepartamento(tDepartamento* depto)
{
    free (depto->c1);
    free (depto->c2);
    free (depto->c3);

    free (depto->nome);
    free (depto->diretor);

    free (depto);
}


/**
 * @brief Imprime os atributos do departamento, sendo eles: cursos, nome do departamento, média por curso e nome do diretor.
 * 
 * @param depto Departamento cujos atributos serão impressos.
 */
void ImprimeAtributosDepartamento (tDepartamento* depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto->nome);
    printf("diretor => %s\n", depto->diretor);
    printf("curso1 => %s, media1 => %d\n", depto->c1, depto->m1);
    printf("curso2 => %s, media2 => %d\n", depto->c2, depto->m2);
    printf("curso3 => %s, media3 => %d\n", depto->c3, depto->m3);
    printf("media geral => %.2f\n", depto->media_geral);
    printf("desvio padrao => %.2f\n", CalculaDesvioPadraoDepartamento(depto));
    printf("\n");
}

/**
 * @brief Verifica se a media inserida é valida, ou seja, pertence à [0, 10].
 * 
 * @param media Valor a ser validado.
 * @return int Se é válida (1) ou não (0).
 */
int ValidaMediaDepartamento (int media)
{
    return 0 <= media && media <= 10;
}

/**
 * @brief Calcula o Desvio Padrão das médias por curso de um departamento.
 * 
 * @param depto Departamento cujo Desvio Padrão de médias por curso deve ser calculado.
 * @return double Valor do cálculo do Desvio Padrão.
 */
double CalculaDesvioPadraoDepartamento(tDepartamento* depto)
{
    double variancia = (
        pow(depto->m1 - depto->media_geral, 2) + 
        pow(depto->m2 - depto->media_geral, 2) + 
        pow(depto->m3 - depto->media_geral, 2)
    );
 
    return sqrt(variancia / 3.0);
}

/**
 * @brief Calcula a média simples das notas dos cursos do departamento.
 * 
 * @param depto Departamento cuja media simples deve ser calculada.
 * @return double Valor do calculo da média simples.
 */
double CalculaMediaGeralDepartamento(tDepartamento* depto)
{
    return (depto->m1 + depto->m2 + depto->m3) / 3.0;
}

/**
 * @brief Ordena o vetor de departamentos em ordem decrescente de acordo com as médias dos departamentos.
 * 
 * @param deptos Vetor de departamentos a ser ordenado.
 * @param tamanho Tamanho do vetor a ser ordenado.
 */
void OrdenaPorMediaDepartamentos(tDepartamento* d[], int tamanho)
{
    for (int i = 0; i < tamanho - 1; i++)
    {
        for (int j = 0; j < tamanho - 1-i; j++)
        {
            if (d[j]->media_geral < d[j + 1]->media_geral)
            {
                tDepartamento *aux = d[j];
                d[j] = d[j + 1];
                d[j + 1] = aux;
            }
        }
    }
}