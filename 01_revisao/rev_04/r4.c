/* 
Um programa que recebe um número inteiro decimal e converte-o para um número um octal.
Catarian Lemos
24/03/2026
*/

#include <stdio.h>

#define BASE 8

int divideNum (int num)
{
    int restos = 0;
    int potencia = 1;

    while (num > 0)
    {
        int digito = num % BASE;
        restos = restos + (digito * potencia);
        num /= BASE;
        potencia *= 10;
    }

    return restos;
}

int main()
{
    int decimal;
    scanf("%d", &decimal);

    int novoNum = divideNum(decimal);
    printf("%d\n", novoNum);

    return 0;
}