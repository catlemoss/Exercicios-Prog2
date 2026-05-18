#include <stdio.h>

#include "eleitor.h"

tEleitor CriaEleitor(int id, int votoP, int votoG)
{
    tEleitor e;

    e.id = id;
    e.votoP = votoP;
    e.votoG = votoG;

    return e;
}

tEleitor LeEleitor()
{
    tEleitor e;

    scanf("%d %d %d", &e.id, &e.votoP, &e.votoG);

    return e;
}
 
int ObtemVotoPresidente(tEleitor eleitor)
{
    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor)
{
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2)
{
    return eleitor1.id == eleitor2.id;
}