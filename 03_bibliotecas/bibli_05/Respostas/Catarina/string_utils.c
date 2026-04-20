#include <stdio.h>
#include <ctype.h>

#include "string_utils.h"

int string_length(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

void string_copy(char *src, char *dest)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';                     // stop right there buddy
}

void string_upper(char *str)
{
    int len = string_length(str);

    for (int i = 0; i < len; i++)
    {
        str[i] = toupper(str[i]);
    }
}

void string_lower(char *str)
{
    int len = string_length(str);

    for (int i = 0; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void string_reverse(char *str)
{
    int len = string_length(str);

    for (int i = 0; i < len/2; i++)                // /2 para para a inversao no meio
    {
        char aux = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = aux;
    }
}