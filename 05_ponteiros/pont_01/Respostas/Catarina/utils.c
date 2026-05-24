#include "utils.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Troca os valores de duas variáveis inteiras.
 * 
 * Esta função recebe como parâmetro dois ponteiros para inteiros e troca os valores armazenados nas variáveis apontadas por eles.
 * 
 * @param n1 Ponteiro para a primeira variável a ser trocada.
 * @param n2 Ponteiro para a segunda variável a ser trocada.
 * @return 1 se a troca foi realizada com sucesso, 0 caso contrário.
 */
int TrocaInterios(int * n1, int * n2)
{
    int aux;

    if (*n1 <= *n2) return 0;

    if (*n1 > *n2)
    {
        aux = *n1;  // guarda o valor apontado por n1
        *n1 = *n2;  // coloca no lugar de n1 o valor apontado por n2
        *n2 = aux;  // coloca no lugar de n2 o valor antigo de n1
        
        return 1;
    }
}

// int *p = &x; // p aponta para x
// p = &y;