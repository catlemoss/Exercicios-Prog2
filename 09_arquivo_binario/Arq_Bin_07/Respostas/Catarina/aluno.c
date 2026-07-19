#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"

struct Aluno
{
    char nome[50];
    char dataBirth[12];
    char curso[50];
    float conclusao;
    float cr;
};

/**
 * @brief Cria um novo aluno.
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso do aluno.
 * @param prctConclusao Percentual de conclusão do curso.
 * @param cfRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para a estrutura do aluno criada. Caso a alocação falhe, a função termina o programa.
 */
tAluno *CriaAluno(char *nome, char *dataNascimento, char *curso, float prctConclusao, float cfRendimento)
{
    tAluno *aluno = calloc (1, sizeof(*aluno));
    if (aluno == NULL) exit (1);

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataBirth, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->conclusao = prctConclusao;
    aluno->cr = cfRendimento;

    return aluno;
}

/**
 * @brief Destroi um aluno.
 * @param aluno Ponteiro para a estrutura do aluno a ser destruída.
 */
void DestroiAluno(tAluno *aluno)
{
    free (aluno);
}

/**
 * @brief Lê um aluno da entrada padrão.
 * @return Um ponteiro para a estrutura do aluno lida.
 */
tAluno *LeAluno()
{
    tAluno *aluno = calloc (1, sizeof(*aluno));
    if (aluno == NULL) exit (1);

    scanf(" %49[^\n]", aluno->nome);
    scanf(" %11s", aluno->dataBirth);
    scanf(" %49[^\n]", aluno->curso);

    scanf(" %f", &aluno->conclusao);
    scanf(" %f", &aluno->cr);

    return aluno;
}

/**
 * @brief Compara o nome de dois alunos.
 * @param aluno1 Ponteiro para a estrutura do primeiro aluno.
 * @param aluno2 Ponteiro para a estrutura do segundo aluno.
 * @return Um inteiro indicando o resultado da comparação, conforme a função strcmp.
 */
int ComparaNomeAluno(tAluno *aluno1, tAluno *aluno2)
{
    return strcmp(aluno1->nome, aluno2->nome);
}

/**
 * @brief Salva um aluno em um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser salva.
 * @param file Ponteiro para o arquivo onde o aluno será salvo.
 * @return Um inteiro indicando o número de bytes salvos deste aluno.
 */
int SalvaAluno(tAluno *aluno, FILE *file)
{
    int bytes = 0;

    bytes += fwrite(aluno->nome, sizeof(char), 50, file);
    bytes += fwrite(aluno->dataBirth, sizeof(char), 12, file);
    bytes += fwrite(aluno->curso, sizeof(char), 50, file);
    bytes += fwrite(&aluno->conclusao, sizeof(float), 1, file);
    bytes += fwrite(&aluno->cr, sizeof(float), 1, file);

    return bytes;
}

/**
 * @brief Carrega um aluno de um arquivo binário.
 * @param aluno Ponteiro para a estrutura do aluno a ser carregada.
 * @param file Ponteiro para o arquivo de onde o aluno será carregado.
 * @return Um inteiro indicando o número de bytes lidos deste aluno.
 */
int CarregaAluno(tAluno *aluno, FILE *file)
{
    int bytes = 0;

    bytes += fread (aluno->nome, sizeof(char), 50, file);
    bytes += fread(aluno->dataBirth, sizeof(char), 12, file);
    bytes += fread(aluno->curso, sizeof(char), 50, file);
    bytes += fread(&aluno->conclusao, sizeof(float), 1, file);
    bytes += fread(&aluno->cr, sizeof(float), 1, file);

    return bytes;
}

/**
 * @brief Imprime o nome de um aluno na saída padrão.
 * @param aluno Ponteiro para a estrutura do aluno cujo nome será impresso.
 */
void ImprimeNomeAluno(tAluno *aluno)
{
    printf("%s\n", aluno->nome);
}