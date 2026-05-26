/*
Um programa para saber se um ponto está ou não dentro de um círculo.
Catarina Lemos
26/05/2026
*/

#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    float c1, c2;       // centro x e centro y
    float raio;
    float x, y;

    scanf("%f %f %f %f %f", &c1, &c2, &raio, &x, &y);

    tCirculo circulo = Circulo_Cria(c1, c2, raio);
    tPonto ponto = Pto_Cria(x, y);

    int dentro = Circulo_Interior(circulo, ponto);
    printf("%d\n", dentro);

    Pto_Apaga(ponto);
    Circulo_Apaga(circulo);

    return 0;
}