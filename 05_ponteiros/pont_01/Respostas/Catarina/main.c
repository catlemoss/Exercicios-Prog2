/*
Dado o programa abaixo que lê pares de números separados por
espaço e imprime os números em sua ordem original quando o primeiro é menor ou
igual ao segundo e em ordem inversa quando o primeiro é maior do que o segundo.
Catarina Lemos
24/05/2026
*/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

//Defina e implemente TrocaInterios

int main()
{
    int n1, n2;

    while ( scanf("%d %d", &n1, &n2) == 2 )
    {
        if ( TrocaInterios(&n1, &n2) )
        {
            printf("TROCADO: %d %d\n", n1, n2);
        } 
        
        else 
        {
            printf("ORIGINAL: %d %d\n", n1, n2);
        }
    }

    return 0;
}