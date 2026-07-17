#include "base_alunos.h"
#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Estrutura para representar uma base de alunos.
 */
struct BaseAlunos
{
    tAluno **alunos;
    int qnt;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *base = malloc (sizeof (*base));
    if (base == NULL) exit (1);

    base->alunos = NULL;
    base->qnt = 0;

    return base;
}

/**
 * @brief Função para destruir uma base de alunos.
 * 
 * @param baseAlunos A base de alunos a ser destruída.
 */
void DestruirBaseAlunos(tBaseAlunos* baseAlunos)
{
    for (int i = 0; i < baseAlunos->qnt; i++)
    {
        DestruirAluno (baseAlunos->alunos[i]);
    }

    free (baseAlunos->alunos);
    free (baseAlunos);
}

/**
 * @brief Função para ler uma base de alunos de um arquivo binário.
 * 
 * @param baseAlunos A base de alunos para ler o arquivo.
 * @param nomeArquivo O nome do arquivo a ser lido.
 */
void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo)
{
    FILE *arq = fopen (nomeArquivo, "rb");
    if (arq == NULL) exit (1);

    fread (&baseAlunos->qnt, sizeof(int), 1, arq);

    baseAlunos->alunos = malloc (baseAlunos->qnt * sizeof(baseAlunos->alunos));
    if (baseAlunos == NULL) { fclose (arq), exit (1); }

    for (int i = 0; i < baseAlunos->qnt; i++)
    {
        baseAlunos->alunos[i] = LeAluno(arq);
    }

    fclose (arq);
}

/**
 * @brief Função para obter o coeficiente de rendimento médio de uma base de alunos.
 * 
 * @param baseAlunos A base de alunos para obter o coeficiente de rendimento médio.
 * @return O coeficiente de rendimento médio da base de alunos.
 */
float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos)
{
    float soma = 0;

    for (int i = 0; i < baseAlunos->qnt; i++)
    {
        soma += GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]);
    }

    return soma / baseAlunos->qnt;
}