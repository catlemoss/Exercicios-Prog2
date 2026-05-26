/*
Crie um programa que leia uma sequência de números e os armazene
em um vetor alocado dinamicamente.
Catarina Lemos
26/05/2026
*/

#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int num;
    scanf("%d\n", &num);

    int *vet = CriaVetor(num);

    LeVetor(vet, num);

    float media = CalculaMedia(vet, num);
    printf("%.2f\n", media);

    LiberaVetor(vet);

    return 0;
}