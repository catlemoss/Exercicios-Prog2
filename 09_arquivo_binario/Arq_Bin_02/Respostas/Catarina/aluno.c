#include "aluno.h"

#include <stdlib.h>
#include <string.h>

/**
 * @brief Estrutura para representar um aluno.
 */
struct Aluno
{
    char nome[100];
    char dataBirth[11];
    char curso[50];

    float periodo;
    float CR;
};

/**
 * @brief Função para criar um novo aluno.
 * 
 * @param nome Nome do aluno.
 * @param dataNascimento Data de nascimento do aluno.
 * @param curso Curso em que o aluno está matriculado.
 * @param periodo Período do curso em que o aluno está.
 * @param coeficienteRendimento Coeficiente de rendimento do aluno.
 * @return Um ponteiro para o aluno recém-criado. Se houver erro na alocação de memória, o programa é encerrado.
 */
tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento)
{
    tAluno *aluno = malloc (sizeof (*aluno));
    if (aluno == NULL) exit (1);

    strcpy(aluno->nome, nome);
    strcpy(aluno->dataBirth, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->periodo = periodo;
    aluno->CR = coeficienteRendimento;

    return aluno;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    free (aluno);
}

/**
 * @brief Função para ler um aluno de um arquivo binário.
 * 
 * @param arquivo_binario O arquivo binário para ler o aluno.
 * @return Um ponteiro para o aluno lido.
 */
tAluno *LeAluno(FILE *arquivo_binario)
{
    char nome[101];
    char dataBirth[12];
    char curso[51];

    float periodo;
    float CR;

    scanf(" %[^\n]", nome);
    scanf(" %[^\n]", dataBirth);
    scanf(" %[^\n]", curso);

    scanf("%f", &periodo);
    scanf("%f", &CR);

    fread (nome, sizeof(char), 100, arquivo_binario);
    fread (dataBirth, sizeof(char), 11, arquivo_binario);
    fread (curso, sizeof(char), 50, arquivo_binario);

    fread (&periodo, sizeof(float), 1, arquivo_binario);
    fread (&CR, sizeof(float), 1, arquivo_binario);

    tAluno *aluno = CriarAluno (nome, dataBirth, curso, periodo, CR);

    return aluno;
}

/**
 * @brief Função para obter o coeficiente de rendimento de um aluno.
 * 
 * @param aluno O aluno para obter o coeficiente de rendimento.
 * @return O coeficiente de rendimento do aluno.
 */
float GetCoeficienteRendimentoAluno(tAluno* aluno)
{
    return aluno->CR;
}