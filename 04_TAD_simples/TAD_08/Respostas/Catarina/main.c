/*
Crie um TAD do tipo Departamento que contenha diversas funções
relativas à organização interna de um departamento de uma universidade.
Catarina Lemos
22/05/2026
*/

#include "departamento.h"

#include <stdio.h>

int main ()
{
    int nDepartamentos;
    scanf("%d", &nDepartamentos);

    char nome[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;
    char diretor [STRING_MAX];

    tDepartamento dep[nDepartamentos];

    int qntDeps = 0;

    for (int i = 0; i < nDepartamentos; i++)
    {
        scanf("%s", nome);
        scanf("%s", diretor);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", &m1, &m2, &m3);

        if (validaMediaDepartamento(m1) && validaMediaDepartamento(m2) && validaMediaDepartamento(m3))
        {
            dep[qntDeps] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);

            dep[qntDeps].media_geral = calculaMediaGeralDepartamento(dep[qntDeps]);
            qntDeps++;
        }
    }

    ordenaPorMediaDepartamentos(dep, qntDeps);
    

    for (int i = 0; i < qntDeps; i++)
    {
        imprimeAtributosDepartamento(dep[i]);
    }

    return 0;
}
