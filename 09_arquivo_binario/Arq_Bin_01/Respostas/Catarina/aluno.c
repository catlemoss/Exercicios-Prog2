#include "aluno.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[100];
    char dataNascimento[100];
    char curso[100];
    char periodoIngresso[100];

    int perConclusao;

    float CR;
};

Aluno** CriaVetorAlunos(int numeroAlunos)
{
    Aluno **vetorAlunos = malloc (numeroAlunos * sizeof(Aluno *));
    if (vetorAlunos == NULL)
    {
        printf("Erro ao alocar memória para VETOR!\n");
        exit (1);
    }

    return vetorAlunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA)
{
    Aluno *a = malloc (sizeof (Aluno));
    if (a == NULL)
    {
        printf("Erro ao alocar memória para ALUNO!\n");
        exit (1);
    }

    strcpy(a->nome, nome);
    strcpy(a->dataNascimento, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodoIngresso, periodoIngresso);

    a->perConclusao = percConclusao;
    a->CR = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos)
{
    char nome[100];
    char dataNascimento[20];
    char curso[100];
    char periodoIngresso[20];
    int perConclusao;
    float CR;

    for (int i = 0; i < numeroAlunos; i++)
    {
        scanf(" %[^\n]", nome);
        scanf(" %[^\n]", dataNascimento);
        scanf(" %[^\n]", curso);
        scanf(" %[^\n]", periodoIngresso);

        scanf("%d", &perConclusao);
        scanf("%f", &CR);

        vetorAlunos[i] = CriaAluno(
            nome, 
            dataNascimento, 
            curso, 
            periodoIngresso, 
            perConclusao, 
            CR
        );
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        free (alunos[i]);
    }

    free (alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos)
{
    FILE *arq = fopen (fileName, "wb");
    if (arq == NULL)
    {
        printf("Erro ao salvar alunos!\n");
        exit (1);
    }

    int bytes = 0;

    bytes = fwrite (&numeroAlunos, sizeof(int), 1, arq) * sizeof(int);

    for (int i = 0; i < numeroAlunos; i++)
    {
        int tam;
        /*
            int tam = strlen(texto);
            fwrite(&tam, sizeof(int), 1, arq);
            fwrite(texto, sizeof(char), tam, arq);
        */

        // nome
        tam     = strlen (alunos[i]->nome);
        bytes  += fwrite (&tam, sizeof(int), 1, arq) * sizeof(int);
        bytes  += fwrite (alunos[i]->nome, sizeof(char), tam, arq) * sizeof(char);

        // data
        tam     = strlen (alunos[i]->dataNascimento);
        bytes  += fwrite (&tam, sizeof(int), 1, arq) * sizeof(int);
        bytes  += fwrite (alunos[i]->dataNascimento, sizeof(char), tam, arq) * sizeof(char);

        // curso
        tam     = strlen (alunos[i]->curso);
        bytes  += fwrite (&tam, sizeof(int), 1, arq) * sizeof(int);
        bytes  += fwrite (alunos[i]->curso, sizeof(char), tam, arq) * sizeof(char);

        // periodo ingrid
        tam     = strlen (alunos[i]->periodoIngresso);
        bytes  += fwrite (&tam, sizeof(int), 1, arq) * sizeof(int);
        bytes  += fwrite (alunos[i]->periodoIngresso, sizeof(char), tam, arq) * sizeof(char);

        // perc to finale
        bytes  += fwrite (&alunos[i]->perConclusao, sizeof(int), 1, arq) * sizeof(int);

        // cr
        bytes  += fwrite (&alunos[i]->CR, sizeof(float), 1, arq) * sizeof(float);

        // esse sizeof no final é para contar quantos foram lidos
    }

    fclose (arq);

    printf("Numero de bytes salvos: %d\n", bytes);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName)
{
    FILE *arq = fopen (fileName, "rb");
    if (arq == NULL)
    {
        printf("Erro ao carregar alunos!\n");
        exit (1);
    }

    int numeroAlunos;
    fread (&numeroAlunos, sizeof(int), 1, arq);

    for (int i = 0; i < numeroAlunos; i++)
    {
        Aluno *a = malloc (sizeof (Aluno));

        int tam;

        fread (&tam, sizeof(int), 1, arq);
        fread (a->nome, sizeof(char), tam, arq);
        a->nome[tam] = '\0';

        fread (&tam, sizeof(int), 1, arq);
        fread (a->dataNascimento, sizeof(char), tam, arq);
        a->dataNascimento[tam] = '\0';

        fread (&tam, sizeof(int), 1, arq);
        fread (a->curso, sizeof(char), tam, arq);
        a->curso[tam] = '\0';

        fread (&tam, sizeof(int), 1, arq);
        fread (a->periodoIngresso, sizeof(char), tam, arq);
        a->periodoIngresso[tam] = '\0';

        fread (&a->perConclusao, sizeof(int), 1, arq);
        fread (&a->CR, sizeof(float), 1, arq);

        alunos[i] = a;
    }

    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos)
{
    for (int i = 0; i < numeroAlunos; i++)
    {
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dataNascimento);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->perConclusao);
        printf("CRA: %.2f\n", alunos[i]->CR);
    }
}