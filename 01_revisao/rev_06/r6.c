/*
Uma loja quer saber quantos funkos podem entrar em promoção baseado no limite.
Catarina Lemos
06/04/2026
*/

#include <stdio.h>

#define ROTULO 1001                         // 1000 + \0
#define ASCII 256

int ehAlfaNumerico (char c)
{
    if ((c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
    {
        return 1;
    }

    return 0;
}

int main ()
{
    int limite;
    scanf("%d", &limite);

    char lista[ROTULO];
    scanf("%s", lista);

    int contagem[ASCII] = {0};              // 256 caracteres ascii
    // chaves no 0 para a contagem começar em 0

    int i;
    for (i = 0; lista[i] != '\0'; i++)      // aqui eu conto as letras
    {
        if (ehAlfaNumerico(lista[i]))
        {
            contagem[lista[i]]++;
        }
    }

    int find = 0;
    for (i = 0; i < ASCII; i++)             // aqui eu coloco em ordem
    {
        if (contagem[i] > limite)
        {
            printf("%c: %d\n", i, contagem[i]);
            find = 1;
        }
    }

    if (find == 0) printf("NENHUM\n");      // sem promoção #gomennasai
    
    return 0;
}