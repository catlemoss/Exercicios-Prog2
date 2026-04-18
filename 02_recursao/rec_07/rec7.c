/*
Um programa que recebe um número e retorna a soma dos seus dígitos, com recursão.
Catarina Lemos
09/04/2026
*/

#include <stdio.h>

int somaDigito (int n)
{
    if (n == 0) return 0;

    return n % 10 + somaDigito(n / 10);     // pega com o %10 e remove com o /10
}

int main ()
{
    int n;
    scanf("%d", &n);

    printf("%d\n", somaDigito(n));

    return 0;
}