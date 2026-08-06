/*
Neste exercício você deverá implementar um algoritmo
de busca chamado busca binária.
Catarina Lemos
05/08/2026
*/

#include <stdio.h>

#include "array.h"

int main () 
{
    Array *array = CriarArray();
    int elementoBuscado;

    LerArray(array);
    OrdenarArray(array);

    if (scanf("%d", &elementoBuscado) != 1) 
    {
        DestruirArray(array);
        return 1;
    }

    int indice = BuscaBinariaArray(array, elementoBuscado);

    if (indice != -1) 
    {
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, indice);
    } 
    else 
    {
        printf("Elemento %d não encontrado no array (%d).\n", elementoBuscado, indice);
    }

    DestruirArray(array);
    return 0;
}
