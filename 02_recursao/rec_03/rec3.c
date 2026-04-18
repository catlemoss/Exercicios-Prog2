/*
Um programa que recebe um vetor, sua quantidade, um número e retorne quantas vezes o número aparece no vetor.
Catarina Lemos
07/04/2026
*/

#include <stdio.h>

int contaOcorrencias(int vet[], int numElementos, int numProcurado)
{
    if (numElementos < 0) return 0;

    if (vet[numElementos] == numProcurado)
    {
        return 1 + contaOcorrencias(vet, numElementos - 1, numProcurado);
    }

    return contaOcorrencias(vet, numElementos - 1, numProcurado);
}

int main ()
{
    int nCasos;
    scanf("%d", &nCasos);

    int i;
    for (i = 0; i < nCasos; i++)
    {
        int numProcurado, qnt;
        scanf("%d %d", &numProcurado, &qnt);

        int vet[qnt];

        int j;
        for (j = 0; j < qnt; j++) { scanf("%d", &vet[j]); }

        int ocorrencias = contaOcorrencias(vet, qnt - 1, numProcurado);
        
        printf("%d\n", ocorrencias);
    }

    return 0;
}