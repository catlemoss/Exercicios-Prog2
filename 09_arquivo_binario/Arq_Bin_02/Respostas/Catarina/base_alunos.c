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
    int max;
};

/**
 * @brief Função para criar uma nova base de alunos.
 * 
 * @return Um ponteiro para a base de alunos recém-criada. Se houver erro na alocação de memória, o programa é encerrado.
 */
tBaseAlunos* CriarBaseAlunos()
{
    tBaseAlunos *b = malloc (sizeof (tBaseAlunos));
    if (b == NULL)
    {
        printf("Erro ao criar base aluno!\n");
        exit (1);
    }

    b->alunos = NULL;
    b->qnt = 0;
    b->max = 0;

    return b;
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
    FILE *arquivo_binario = fopen (nomeArquivo, "rb");

    if (arquivo_binario == NULL)
    {
        printf("Erro ao ler arquivo %s!\n", nomeArquivo);
        exit(1);
    }

    int qntAlunos;
    if (fread(&qntAlunos, sizeof(int), 1, arquivo_binario) != 1)
    {
        printf("Erro ao ler quantidade de alunos!\n");
        fclose(arquivo_binario);
        exit(1);
    }

    baseAlunos->qnt = 0;
    baseAlunos->max = qntAlunos;

    baseAlunos->alunos = malloc (qntAlunos * sizeof(tAluno *));
    if (qntAlunos > 0 && baseAlunos->alunos == NULL)
    {
        printf("Erro ao alocar vetor de alunos!\n");
        fclose(arquivo_binario);
        exit(1);
    }

    for (int i = 0; i < qntAlunos; i++)
    {
        tAluno *aluno = LeAluno(arquivo_binario);

        if (aluno == NULL)
        {
            printf("Erro ao ler aluno!\n");
            fclose(arquivo_binario);
            exit(1);
        }

        baseAlunos->alunos[baseAlunos->qnt] = aluno;
        baseAlunos->qnt++;
    }

    fclose(arquivo_binario);
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