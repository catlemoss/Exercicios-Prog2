/*
Um programa que identifiqua quais livros da lista não tem cópia e
retorna para o funcionário solicitar a compra.
Catarina Lemos
23/03/2026
*/

#include <stdio.h>

#define MAX 100

int main()
{
    int nLivros;
    scanf("%d", &nLivros);

    int lista[MAX];
    int i;
    for (i = 0; i < nLivros; i++) { scanf("%d", &lista[i]); }
    // guarda numeros no vetor

    int j;
    for (i = 0; i < nLivros; i++)
    {
        int cont = 0;

        for (j = 0; j < nLivros; j++)
        {
            if (lista[i] == lista[j]) cont++;
        }

        if (cont == 1) printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}