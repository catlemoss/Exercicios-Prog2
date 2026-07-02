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
    tAluno *a = malloc (sizeof (tAluno));
    if (a == NULL)
    {
        printf("Erro ao alocar memoria para aluno!\n");
        exit (1);
    }

    strcpy(a->nome, nome);
    strcpy(a->dataBirth, dataNascimento);
    strcpy(a->curso, curso);

    a->periodo = periodo;
    a->CR = coeficienteRendimento;

    return a;
}

/**
 * @brief Função para destruir um aluno.
 * 
 * @param aluno O aluno a ser destruído.
 */
void DestruirAluno(tAluno* aluno)
{
    if (aluno == NULL) return;
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
    char dataNascimento[12];
    char curso[51];
    float periodo;
    float CR;

    if (fread(nome, sizeof(char), 100, arquivo_binario) != 100) return NULL;

    if (fread(dataNascimento, sizeof(char), 11, arquivo_binario) != 11) return NULL;
    
    if (fread(curso, sizeof(char), 50, arquivo_binario) != 50) return NULL;
    
    if (fread(&periodo, sizeof(float), 1, arquivo_binario) != 1) return NULL;
    
    if (fread(&CR, sizeof(float), 1, arquivo_binario) != 1) return NULL;
    

    nome[100] = '\0';
    dataNascimento[11] = '\0';
    curso[50] = '\0';

    tAluno *a = CriarAluno(nome, dataNascimento, curso, periodo, CR);

    return a;
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