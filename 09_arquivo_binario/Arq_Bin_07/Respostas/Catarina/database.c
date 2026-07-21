#include <stdio.h>
#include <stdlib.h>

#include "database.h"
#include "aluno.h"
#include "professor.h"
#include "vector.h"

struct Database
{
    Vector *alunos;
    Vector *profs;
};

/**
 * @brief Cria um nova database.
 * @return Um ponteiro para a estrutura database criada. Caso a alocação falhe, a função termina o programa.
 */
tDatabase *CriaDatabase()
{
    tDatabase *base = calloc(1, sizeof(*base));
    if (base == NULL) exit (1);

    base->alunos = VectorConstruct();
    base->profs = VectorConstruct();

    return base;
}

/**
 * @brief Destroi uma database.
 * @param db Ponteiro para a estrutura da database a ser destruída.
 */
void DestroiDatabase(tDatabase *db)
{
    VectorDestroy(db->alunos, (void(*)(DataType))DestroiAluno);
    VectorDestroy(db->profs, (void(*)(DataType))DestroiProfessor);

    free(db);
}

/**
 * @brief Lê uma database da entrada padrão.
 * @param db Ponteiro para a estrutura da database a ser lida.
 */
void LeDatabase(tDatabase *db)
{
    int qntAlunos = 0;
    int qntProfs = 0;

    scanf(" %d", &qntAlunos);

    for (int i = 0; i < qntAlunos; i++)
    {
        VectorPushBack(db->alunos, LeAluno());
    }

    scanf(" %d", &qntProfs);

    for (int i = 0; i < qntProfs; i++)
    {
        VectorPushBack(db->profs, LeProfessor());
    }
}

/**
 * @brief Ordena uma database, primeiro os alunos e depois os professores, de acordo com o nome.
 * @param db Ponteiro para a estrutura da database a ser ordenada.
 */
void OrdenaDatabase(tDatabase *db)
{
    int qntAlunos = VectorSize(db->alunos);

    for (int i = 0; i < qntAlunos -1; i++)
    {
        for (int j = 0; j < qntAlunos -1-i; j++)
        {
            tAluno *a1 = VectorGet(db->alunos, j);
            tAluno *a2 = VectorGet(db->alunos, j + 1);

            if (ComparaNomeAluno(a1, a2) > 0)
            {
                VectorSwap(db->alunos, j, j + 1);
            }
        }
    }

    int qntProfs = VectorSize(db->profs);

    for (int i = 0; i < qntProfs -1; i++)
    {
        for (int j = 0; j < qntProfs - 1-i; j++)
        {
            tProfessor *p1 = VectorGet(db->profs, j);
            tProfessor *p2 = VectorGet(db->profs, j + 1);

            if (ComparaNomeProfessor(p1, p2) > 0)
            {
                VectorSwap(db->profs, j, j + 1);
            }
        }
    }
}

/**
 * @brief Salva uma database em um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser salva.
 * @param file Ponteiro para o arquivo onde a database será salva.
 * @return Um inteiro indicando o total de bytes salvos.
 */
int SalvarDatabase(tDatabase *db, FILE *file)
{
    int bytes = 0;

    int qntAlunos = VectorSize(db->alunos);
    int qntProfs = VectorSize(db->profs);

    bytes += fwrite(&qntAlunos, sizeof(int), 1, file);

    for (int i = 0; i < qntAlunos; i++)
    {
        bytes += SalvaAluno(VectorGet(db->alunos, i), file);
    }

    bytes += fwrite(&qntProfs, sizeof(int), 1, file);

    for (int i = 0; i < qntProfs; i++)
    {
        bytes += SalvaProfessor(VectorGet(db->profs, i), file);
    }

    return bytes;
}

/**
 * @brief Carrega uma database de um arquivo binário.
 * @param db Ponteiro para a estrutura da database a ser carregada.
 * @param file Ponteiro para o arquivo de onde a database será carregada.
 * @return Um inteiro indicando o total de bytes lidos.
 */
int CarregaDatabase(tDatabase *db, FILE *file)
{
    int bytes = 0;

    int qntAlunos = 0;
    int qntProfs = 0;

    bytes += fread(&qntAlunos, sizeof(int), 1, file);

    for (int i = 0; i < qntAlunos; i++)
    {
        tAluno *aluno = CriaAluno("", "", "", 0.0f, 0.0f);
        bytes += CarregaAluno(aluno, file);
        VectorPushBack(db->alunos, aluno);
    }

    bytes += fread(&qntProfs, sizeof(int), 1, file);

    for (int i = 0; i < qntProfs; i++)
    {
        tProfessor *prof = CriaProfessor("", "", "");
        bytes += CarregaProfessor(prof, file);
        VectorPushBack(db->profs, prof);
    }

    return bytes;
}

/**
 * @brief Imprime uma database, primeiro os alunos e depois os professores. Apenas os nomes são impressos.
 * @param db Ponteiro para a estrutura da database a ser impressa.
 */
void ImprimeDatabase(tDatabase *db)
{
    printf("Alunos:\n");

    for (int i = 0; i < VectorSize(db->alunos); i++)
    {
        ImprimeNomeAluno(VectorGet(db->alunos, i));
    }

    printf("\nProfessores:\n");

    for (int i = 0; i < VectorSize(db->profs); i++)
    {
        ImprimeNomeProfessor(VectorGet(db->profs, i));
    }
}