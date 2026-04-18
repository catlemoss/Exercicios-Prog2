/*
Um programa para calcular fatoriais, com recursão.
Catarina Lemos
09/04/2026
*/

#include <stdio.h>

int fatorial (int n)
{
    if (n <= 1) return 1;           // condicao de parada

    return n * fatorial(n-1);
}

int main ()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", fatorial(n));

    return 0;
}