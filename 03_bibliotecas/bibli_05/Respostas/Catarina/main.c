/*
Uma biblioteca que forneça uma variedade de funções para
manipulação de strings.
Catarina Lemos
20/04/2026 (ainda é aniversário do Bakugo)
*/

#include <stdio.h>
#include <ctype.h>

#include "string_utils.h"

#define MAX_LEN 100

int main ()
{
    char frase[MAX_LEN];
    scanf(" %[^\n]", frase);

    int opcao;

    while (1)
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:");

        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 6) break;

        if (opcao == 1)
        {
            printf("Tamanho da string: %d\n\n", string_length(frase));
        }

        if (opcao == 2)
        {
            char copia[MAX_LEN];
            string_copy(frase, copia);

            printf("String copiada: %s\n\n", copia);
        }

        if (opcao == 3)
        {
            char aux[MAX_LEN];
            string_copy(frase, aux);
            // faz uma copia para nao mudar a string original

            string_upper(aux);

            printf("String convertida para maiusculas: %s\n\n", aux);
        }

        if (opcao == 4)
        {
            char aux[MAX_LEN];
            string_copy(frase, aux);

            string_lower(aux);

            printf("String convertida para minusculas: %s\n\n", aux);
        }

        if (opcao == 5)
        {
            char aux[MAX_LEN];
            string_copy(frase, aux);

            string_reverse(aux);

            printf("String invertida: %s\n\n", aux);
        }
    }

    return 0;
}
