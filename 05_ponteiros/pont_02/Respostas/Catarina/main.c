/*
Dado o programa para mostrar o menor e o maior primo de um intervalo fechado, implemente as duas funções (LeIntervalo e ObtemMaiorEMenorPrimo) que faltam para o programa funcionar corretamente.
Catarina Lemos
24/05/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

int main(int argc, char * argv[])
{
    int casos;
    scanf("%d", &casos);

    while(casos)
    {
        int m, n, menor, maior;

        LeIntervalo(&m, &n);

        ObtemMaiorEMenorPrimo(m, n, &menor, &maior);

        printf("%d %d\n", menor, maior);

        casos--;
    }
    
    return 0;
}