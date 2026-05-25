/*
Dado o programa abaixo que lê uma sequência numérica e
imprime na tela o maior, o menor e a média da sequência, implemente a função que
realiza todas essas operações sem retornar um valor.
Catarina Lemos
25/05/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main()
{
    int tamanho;
    scanf("%d", &tamanho);

    int numeros[tamanho];

    LeNumeros(numeros, tamanho);

    int maior, menor;
    float media;

    EncontraMaiorMenorMedia(numeros, tamanho, &maior, &menor, &media);

    printf("Maior elemento: %d\n", maior);
    printf("Menor elemento: %d\n", menor);
    printf("Media dos elementos: %.2f\n", media);
    
    return 0;
}