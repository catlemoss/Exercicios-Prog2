/*
Dado o programa abaixo para ler e mostrar os dados ordenados
(em ordem crescente) de vetores, implemente as três funções (LeDadosParaVetor,
OrdeneCrescente e ImprimeDadosDoVetor) que faltam para o programa funcionar
corretamente.
Catarina Lemos
25/05/2026
*/

#include <stdio.h>
#include <stdlib.h>

#include "vetor.h"

int main (int argc, char * argv[])
{
    int casos;
    scanf("%d", &casos);

    while(casos)
    {
        int tam;
        scanf("%d", &tam);

        int vet[tam];

        LeDadosParaVetor(vet, tam);

        OrdeneCrescente(vet, tam);

        ImprimeDadosDoVetor(vet, tam);

        casos--;
    }
    
    return 0;
}