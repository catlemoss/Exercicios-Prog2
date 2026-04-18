/*
Um programa que recebe uma string e tamanho e retorne verdadeiro se for palindroma, com recursão.
Catarina Lemos
07/04/2026
*/

#include <stdio.h>
#include <string.h>

#define MAX_CHAR 50

int palindromo (char string[], int i, int tamanho)
{
    if (string[tamanho] != string[i-1]) return 0;

    if (i > 0)
    {
        return palindromo (string, i-1, tamanho+1);
    }

    return 1;
}

int main ()
{
    char string[MAX_CHAR];
    int i = 0;
    
    while (scanf("%s", string) == 1)
    {
        i = strlen(string);

        if (palindromo(string, i, 0))
        {
            printf("SIM\n");

        } else printf("NAO\n");
    }

    return 0;
}