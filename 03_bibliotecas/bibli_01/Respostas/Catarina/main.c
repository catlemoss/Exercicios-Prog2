/*
Um programa com uma biblioteca que armazene funções para calcular a área e o
volume de uma esfera.
Catarina Lemos
18/04/2026
*/

#include <stdio.h>

#include "esfera_utils.h"

int main ()
{
    float raio;
    scanf("%f", &raio);

    float volume = calcula_volume(raio);
    float area_sup = calcula_area(raio);

    printf("Area: %.2f\n", area_sup);
    printf("Volume: %.2f\n", volume);

    return 0;
}