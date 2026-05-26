/*
Crie um programa que leia uma sequência de caracteres e os
armazene em um vetor alocado dinamicamente.
Catarina Lemos
26/05/2026
*/

#include "utils_char2.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
    char *palavra = CriaVetorTamPadrao();

    int tamanho = strlen(palavra);

    palavra = LeVetor(palavra, &tamanho);

    ImprimeString(palavra);

    LiberaVetor(palavra);

    return 0;
}