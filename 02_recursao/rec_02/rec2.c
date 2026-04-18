/*
Um programa que recebe um vetor e retorna a soma dos elementos que são pares, com recursão.
Catarina Lemos
07/04/2026
*/

#include <stdio.h>

int SomaElementosPares(int vet[], int numElementos)
{
    if (numElementos < 0) return 0;          // condicao de parada

    if (vet[numElementos] % 2 == 0)
    {
        return vet[numElementos] + SomaElementosPares(vet, numElementos - 1);
    }

    return SomaElementosPares(vet, numElementos - 1);
}

int main ()
{
    int nVetores;                           // numero de vetores a serem lidos
    scanf("%d", &nVetores);

    int i;
    for (i = 0; i < nVetores; i++)
    {
        int qnt;                            // numero de numeros dentro do vetor
        scanf("%d", &qnt);

        int vet[qnt];

        int j;
        for (j = 0; j < qnt; j++) { scanf("%d", &vet[j]); }

        int soma = SomaElementosPares(vet, qnt - 1);

        printf("%d\n", soma);
    }

    return 0;
}