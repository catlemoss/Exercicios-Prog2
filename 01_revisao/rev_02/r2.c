/*
Um programa que recebe um valor inteiro N e imprime as
N linhas do triângulo a seguir, conhecido como triangulo de Floyd.
Catarina Lemos
23/03/2026
*/

#include <stdio.h>

int main ()
{
    int N; // N linhas de um triangulo
    scanf("%d", &N);

    int cont = 1; // a variavel deve ser externa ao for, ja que ela segue uma ordem

    int i, j;
    for (i = 1; i <= N; i++) // linhas
    {
        for (j = 1; j <= i; j++) // colunas
        {
            printf("%d ", cont);
            cont++;
        }
        printf("\n");
    }

    return 0;
}