/*
Crie um TAD do tipo Departamento que contenha diversas funçõ es
relativas à organizaçã o interna de um departamento de uma universidade.
Catarina Lemos
04/08/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "departamento.h"

int main ()
{
    int nDepartamentos;
    scanf("%d", &nDepartamentos);

    char nome[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;
    char diretor [STRING_MAX];

    tDepartamento **vet = malloc(nDepartamentos * sizeof(*vet));;
    tDepartamento *dep;

    int qntDeps = 0;

    for (int i = 0; i < nDepartamentos; i++)
    {
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", &m1, &m2, &m3);

        if (ValidaMediaDepartamento(m1) && ValidaMediaDepartamento(m2) && ValidaMediaDepartamento(m3))
        {
            dep = CriaDepartamento();
            PreencheDadosDepartamento(dep, c1, c2, c3, nome, m1, m2, m3, diretor);

            dep->media_geral = CalculaMediaGeralDepartamento(dep);

            vet[qntDeps] = dep;
            qntDeps++;
        }
    }

    OrdenaPorMediaDepartamentos(vet, qntDeps);
    

    for (int i = 0; i < qntDeps; i++)
    {
        ImprimeAtributosDepartamento(vet[i]);
    }

    for (int i = 0; i < qntDeps; i++)
    {
        LiberaMemoriaDepartamento(vet[i]);
    }

    free (vet);

    return 0;
}