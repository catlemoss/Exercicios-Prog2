/*
Crie um programa que leia uma sequência de caracteres e os
armazene em um vetor alocado dinamicamente.
Catarina Lemos
26/05/2026
*/

#include "utils_char.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    int tamanho;
    scanf("%d\n", &tamanho);

    char *palavra = CriaVetor(tamanho);
    ImprimeString(palavra, tamanho);

    LeVetor(palavra, tamanho);
    ImprimeString(palavra, tamanho);

    LiberaVetor(palavra);

    return 0;
}